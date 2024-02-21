from __future__ import print_function
import torch.nn as nn
import torch.optim as optim
import os
import random
import numpy as np
import torch
import torch.nn.functional as F
from data_process import replace_macro, remove_comment, remove_space, verify_correctness, generate_verify_correctness
from model_definition import Transformer
from data_process import get_batch, input_token_index, target_token_index, \
    max_encoder_seq_length, num_encoder_tokens, num_decoder_tokens, max_decoder_seq_length

from torch import Tensor
os.environ["CUDA_VISIBLE_DEVICES"] = "1"

# ---------------------------------------------------------------------
model = Transformer().cuda()
criterion = nn.CrossEntropyLoss(ignore_index=0)
optimizer = optim.SGD(model.parameters(), lr=0.01, momentum=0.9)
batch_size = 256       
# load the model's weight
model_save_dir = 'testsuite/model_save'
model_save_path = os.path.join(model_save_dir, 'epoch50shufll.pt')
model.load_state_dict(torch.load(model_save_path))
model.eval()
maxlen = 50
max_num_line = 2

reverse_input_char_index = dict(
    (i, char) for char, i in input_token_index.items())
reverse_target_char_index = dict(
    (i, char) for char, i in target_token_index.items())


def decode_sequence(input_seq, diversity, sample_method, end_with='no_space'):
    input_seq_data = torch.zeros((1, max_encoder_seq_length))
    for t, char in enumerate(input_seq):
        input_seq_data[0, t] = input_token_index[char]
    input_seq_data = input_seq_data.long().cuda()
    target_seq = torch.zeros(1, 0).type_as(input_seq_data.data).cuda()  
    dec_input = torch.cat([target_seq.detach(), torch.tensor([[target_token_index['\t']]], dtype=input_seq_data.dtype).cuda()], -1)
    dec_input = dec_input.cuda()
    stop_condition = False
    decoded_sentence = ''
    while not stop_condition:                                              
        dec_outputs, _, _, _ = model(input_seq_data, dec_input)  #[batch_size * tgt_len, tgt_vocab_size]
        pro = dec_outputs.cpu()
        sampled_token_index = Sample_methods(F.softmax(pro[-1, :], dim=0), diversity, sample_method, end_with)

        sampled_char = reverse_target_char_index[sampled_token_index]      
        decoded_sentence += sampled_char                                 
        if len(decoded_sentence) > max_decoder_seq_length or sampled_char == '\n' or sampled_char == ';':
            stop_condition = True
        dec_input = torch.cat([dec_input.detach(), torch.tensor([[sampled_token_index]], dtype=input_seq_data.dtype).cuda()], -1)

    if sampled_char == '\n':
        decoded_sentence = decoded_sentence[:-1]
    print('generate:' + decoded_sentence)   
    return decoded_sentence               


def Sample_methods(output: Tensor, temperature=1.0, sample_method='nosample', end_with='no_space'):
    preds = []
    for i in range(output.size(0)):
        preds.append(output[i].item())

    preds = np.log(preds) / temperature              
    exp_preds = np.exp(preds)                    

    preds = exp_preds / np.sum(exp_preds)             
    if sample_method == 'nosample':
        sample_index = np.argmax(preds)
    elif sample_method == 'sample':
        probas = np.random.multinomial(1, preds, 1)      
        sample_index = np.argmax(probas)
    else:             # samplespace method
        if end_with == 'no_space':
            sample_index = np.argmax(preds)
        else:
            arg_preds = np.sum(preds) / len(preds)
            probas = np.random.multinomial(1, preds, 1)  
            sample_index = np.argmax(probas)
            while preds[sample_index] < arg_preds:
                probas = np.random.multinomial(1, preds, 1)  
                sample_index = np.argmax(probas)

    return sample_index


def Nosample(preds, temperature=1.0):
    preds = np.asarray(preds).astype('float64')
    preds = np.log(preds) / temperature               
    exp_preds = np.exp(preds)                         

    preds = exp_preds / np.sum(exp_preds)            
    sample_index = np.argmax(preds)
    return sample_index


def sample(preds, temperature=1.0) :
    preds = np.asarray(preds).astype('float64')


    preds = np.log(preds) / temperature              
    exp_preds = np.exp(preds)                      
    preds = exp_preds / np.sum(exp_preds)            
    probas = np.random.multinomial(1, preds, 1)       

    return np.argmax(probas)                          


def SampleSpace(preds, temperature=1.0, end_with='no_space'):
    preds = np.asarray(preds).astype('float64')
    preds = np.log(preds) / temperature  
    exp_preds = np.exp(preds)  
    preds = exp_preds / np.sum(exp_preds)  

    arg_preds = np.sum(preds) / len(preds)
    probas = np.random.multinomial(1, preds, 1)  
    sample_index = np.argmax(probas)
    if end_with == 'no_space':
        pass
    else:
        while preds[sample_index] < arg_preds :
            probas = np.random.multinomial(1, preds, 1)  
            sample_index = np.argmax(probas)
    return sample_index


# -------------------------------------
def synthesis(text, gmode='g1', smode='nosample'):
    # print('synthesis 1')
    length = len(text)                     
    random.seed()                          
    if (length < maxlen):                   
        return text
    if (gmode == 'g1'):                                    
        prefix_start = random.randrange(length - maxlen)    
        prefix = text[prefix_start:prefix_start + maxlen]   

        generated = prefix                  
        head = text[0 : prefix_start]       
        tail = text[prefix_start + maxlen:]  
        cut_index = tail.find(';') + 1      
        tail = tail[cut_index:]              
        num_line = 0
        k = 0
        while (num_line < max_num_line and k < 150):           
            if (smode == 'nosample'):                         
                next_char = decode_sequence(prefix, 1, smode)        
            if (smode == 'sample'):
                next_char = decode_sequence(prefix, 1.2, smode)
            if (smode == 'samplespace'):
                if (generated[-1] == ' ' or generated[-1] == ';'):  
                    end_with = 'space'
                    next_char = decode_sequence(prefix, 1.2, smode, end_with)
                else:
                    next_char = decode_sequence(prefix, 1, smode)

            if(';' in next_char) :
                num_line += 1                 
            generated += next_char            
            k = k + len(next_char)
            if len(next_char) > max_encoder_seq_length :
                prefix = next_char[-max_encoder_seq_length:]
            else :
                prefix = prefix[len(next_char):] + next_char
                # updata the prefix as the encoder inputs in next epoch
        text = head + generated + tail        
    if (gmode == 'g2'):
        for i in range(2):                    
            length = len(text)                
            prefix_start = random.randrange(length - maxlen)
            prefix = text[prefix_start:prefix_start + maxlen]
            generated = prefix
            head = text[0: prefix_start]
            tail = text[prefix_start + maxlen:]
            cut_index = tail.find(';') + 1
            tail = tail[cut_index:]
            num_line = 0
            k = 0

            while (num_line < max_num_line/2 and k < 150):         
                # k = k + 1
                if (smode == 'nosample'):
                    next_char = decode_sequence(prefix, 1, smode)
                if (smode == 'sample'):
                    next_char = decode_sequence(prefix, 1.2, smode)
                if (smode == 'samplespace'):
                    if (generated[-1] == ' ' or generated[-1] == ';'):
                        end_with = 'space'
                        next_char = decode_sequence(prefix, 1.2, smode, end_with)
                    else:
                        next_char = decode_sequence(prefix, 1, smode)
                if (';' in next_char):
                    num_line += 1
                generated += next_char
                k = k + len(next_char)
                if len(next_char) > max_encoder_seq_length:
                    prefix = next_char[-max_encoder_seq_length:]
                else:
                    prefix = prefix[len(next_char):] + next_char
            text = head + generated + tail

    if (gmode == 'g3'):

        prefix_start = random.randrange(length - maxlen)       
        prefix = text[prefix_start:prefix_start + maxlen]
        generated = prefix
        head = text[0: prefix_start]
        tail = text[prefix_start + maxlen:]                    

        num_chop_line = 0
        while (num_chop_line < max_num_line):   
            cut_index = tail.find(';') + 1  
            tail = tail[cut_index:]        
            num_chop_line += 1
        num_line = 0
        k = 0
        while (num_line < 2 and k < 150):  # max_num_line == 2
            # k = k + 1
            if (smode == 'nosample'):
                next_char = decode_sequence(prefix, 1, smode)
            if (smode == 'sample'):
                next_char = decode_sequence(prefix, 1.2, smode)
            if (smode == 'samplespace'):
                if (generated[-1] == ' ' or generated[-1] == ';'):
                    end_with = 'space'
                    next_char = decode_sequence(prefix, 1.2, smode, end_with)
                else:
                    next_char = decode_sequence(prefix, 1, smode)
            if (';' in next_char):
                num_line += 1
            generated += next_char
            k = k + len(next_char)
            if len(next_char) > max_encoder_seq_length :
                prefix = next_char[-max_encoder_seq_length:]
            else :
                prefix = prefix[len(next_char):] + next_char
        text = head + generated + tail

    print('-' * 50)
    print('head: ')
    print(head)
    print('generated: ')
    print(generated)
    print('tail: ')
    print(tail)
    return text


def generate():
    seed_path = 'testsuite'
    total_count = 0
    syntax_valid_count = 0
    files = []
    for root, d_names, f_names in os.walk(seed_path):
        for f in f_names:
            files.append(os.path.join(root, f))    
    for file in files:
        if ('TR-Fuzz' in file or 'nocomment' in file or 'nospace' in file or 'nomacro' in file or 'raw' in file):
            continue
        if (not file.endswith('.c') and not file.endswith('.h') and not file.endswith('.C')):
            continue
        if total_count >= 10000:
            break
        try:
            text = open(file, 'r').read()                  
            text = replace_macro(text, file)            
            text = remove_comment(text)
            text = remove_space(text)
            is_valid = verify_correctness(text, file, 'TR-Fuzz_original')      
            if (not is_valid):    
                continue
            text = synthesis(text, 'g2', 'nosample')       
            total_count += 1     
            print('total_count:' + str(total_count))
            is_valid = generate_verify_correctness(text, file, 'TR-Fuzz_g2_nosample')    
            if (is_valid):
                syntax_valid_count += 1                 
                print('syntax_valid_count:' + str(syntax_valid_count))
        except:
            continue
    pass_rate = syntax_valid_count / total_count
    print('syntax_valid_count: %d' % (syntax_valid_count))
    print('total_count: %d' % (total_count))
    print('pass rate: %f' % pass_rate)


generate()
