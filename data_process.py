from __future__ import print_function

import random

import torch
from typing import Tuple
from torch import Tensor
import json
import numpy as np
import pdb
import os
os.environ["CUDA_VISIBLE_DEVICES"] = "1"

num_samples = 2000000  # Number of samples to train on.
# Path to the data txt file on disk.
data_path = './testsuite/train_data'
maxlen = 50

input_texts = []
target_texts = []
target_outputs = []
lines = []
input_characters = set()   
target_characters = set()
# vocab = set()    #  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
with open(data_path, 'r', encoding='iso-8859-1') as f:  
    lines = f.read().split('\n')                      
random.shuffle(lines)

for line in lines[: min(num_samples, len(lines) - 1)]:  
    if line != '':
        input_text, target_text = line.split('\t')         

        target = '\t' + target_text
        target_output_text = target_text + '\n'
        input_texts.append(input_text)                     
        target_texts.append(target)                  
        target_outputs.append(target_output_text)


        for char in input_text:
            if char not in input_characters:                
                input_characters.add(char)               


        for char in target:
            if char not in target_characters:              
                target_characters.add(char)                 

        for char in target_output_text:
            if char not in target_characters:              
                target_characters.add(char)                 


input_characters = sorted(list(input_characters))       
target_characters = sorted(list(target_characters))
input_characters.insert(0, 'pad')
target_characters.insert(0, 'pad')
num_encoder_tokens = len(input_characters)            
num_decoder_tokens = len(target_characters)            

max_encoder_seq_length = max([len(txt) for txt in input_texts])     
max_decoder_seq_length = max([len(txt) for txt in target_texts])    


val_num_samples = len(input_texts) // 10  # Number of samples to verification

print('Number of samples:', len(input_texts))                                                 
print('Number of train samples:', min(num_samples, len(lines) - 1)-val_num_samples)          
print('Number of val samples:', val_num_samples)                                           
print('Number of unique input tokens:', num_encoder_tokens)              
print('Number of unique output tokens:', num_decoder_tokens)             
# print('Number of tokens:', num_tokens)      # @@@@@@@@@@@

print('Max sequence length for inputs:', max_encoder_seq_length)         
print('Max sequence length for outputs:', max_decoder_seq_length)        

input_token_index = dict(
    [(char, i) for i, char in enumerate(input_characters)])
target_token_index = dict(
    [(char, i) for i, char in enumerate(target_characters)])

# vocab_tokens

# create tensor
encoder_input_data = torch.zeros((len(input_texts), max_encoder_seq_length))
decoder_input_data = torch.zeros((len(input_texts), max_decoder_seq_length))
decoder_target_data = torch.zeros((len(input_texts), max_decoder_seq_length))


for i, (input_text, target_text, target_out) in enumerate(zip(input_texts, target_texts, target_outputs)):
    for t, char in enumerate(input_text):
        encoder_input_data[i, t] = input_token_index[char]

    for t, char in enumerate(target_text):
        decoder_input_data[i, t] = target_token_index[char]
    for t, char in enumerate(target_out):
        decoder_target_data[i, t] = target_token_index[char]


def get_batch(source: Tensor, batch: int, i: int) -> Tuple[Tensor, Tensor]:
    batch_size = min(batch, len(source) - 1 - i)        
    data = source[i: i+batch_size]                    
    return data


encoder_input_data = encoder_input_data.cuda().long()
decoder_input_data = decoder_input_data.cuda().long()
decoder_target_data = decoder_target_data.cuda().long()

encoder_input = encoder_input_data[:-val_num_samples].cuda()
decoder_input = decoder_input_data[:-val_num_samples].cuda()
decoder_target = decoder_target_data[:-val_num_samples].cuda()

val_encoder_input = encoder_input_data[-val_num_samples:].cuda()
val_decoder_input = decoder_input_data[-val_num_samples:].cuda()
val_decoder_target = decoder_target_data[-val_num_samples:].cuda()
