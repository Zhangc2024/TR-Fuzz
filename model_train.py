import copy
import math
import os
import time
from torch import Tensor
import torch
import numpy as np
import torch.optim as optim
import torch.nn as nn
from data_process import encoder_input, decoder_input, decoder_target, val_encoder_input, val_decoder_input, \
    val_decoder_target, get_batch
from model_definition import Transformer
os.environ["CUDA_VISIBLE_DEVICES"] = "1"
# --------------------------------------------------------------------------------
model = Transformer().cuda()
criterion = nn.CrossEntropyLoss(ignore_index=0)     # our "pad" index is 0
optimizer = optim.SGD(model.parameters(), lr=0.01, momentum=0.9)
batch_size = 256        



def train(model: nn.Module) -> None:
    model.train()                # turn on train mode
    total_loss = 0.              
    all_loss = 0                 # to compute the each batch's average loss in this epoch
    log_interval = 1250         
    start_time = time.time()     
    num_batches = len(encoder_input) // batch_size   # how much batchs in one epoch

    for batch, i in enumerate(range(0, encoder_input.size(0) - 1 , batch_size)):
        data = get_batch(encoder_input, batch_size, i)
        decoder_inputs = get_batch(decoder_input, batch_size, i)
        targets_outputs = get_batch(decoder_target, batch_size, i)
        outputs, enc_self_attns, dec_self_attns, dec_enc_attns = model(data, decoder_inputs)     
        loss = criterion(outputs, targets_outputs.view(-1))
        optimizer.zero_grad()
        loss.backward()            
        torch.nn.utils.clip_grad_norm_(model.parameters(), 0.5)     
        optimizer.step()           
        total_loss += loss.item()           
        all_loss += loss.item()
        if batch % log_interval == 0 and batch > 0:
            spent_time = time.time() - start_time
            per_batch_loss = total_loss / log_interval
            ppl = math.exp(per_batch_loss)
            print(f'| epoch {epoch:3d} | {batch:5d}/{num_batches:5d} batches  '
                  f'| spent_time {spent_time:5.2f} s '
                  f'| loss {per_batch_loss:5.6f} | ppl {ppl:8.6f}')
            total_loss = 0                

    per_batch_loss = all_loss / num_batches
    time_expend = time.time() - start_time
    print(f'| end_epoch {epoch:3d} | **************'
          f'| epoch_time {time_expend:5.2f} s '
          f'| per_batch_loss {per_batch_loss:5.6f}')


def evaluate(model: nn.Module, enc_input: Tensor, dec_input: Tensor, dec_target: Tensor) -> float:
    model.eval()  # turn on evaluation mode     
    total_loss = 0.      
    with torch.no_grad():
        for i in range(0, enc_input.size(0) - 1, batch_size):        
            data = get_batch(enc_input, batch_size, i)    
            decoder_inputs = get_batch(dec_input, batch_size, i)
            targets_outputs = get_batch(dec_target, batch_size, i)
            # seq_len = data.size(0)
            outputs, enc_self_attns, dec_self_attns, dec_enc_attns = model(data, decoder_inputs)             
            total_loss += criterion(outputs, targets_outputs.view(-1))
    return total_loss / (len(enc_input) - 1)  

epochs = 50                         

model_save_dir = 'testsuite/model_save'

print('--------------------Start train---------------------')
for epoch in range(1, epochs + 1):              
    epoch_start_time = time.time()
    train(model)                               
    val_loss = evaluate(model, val_encoder_input, val_decoder_input, val_decoder_target)  
    val_ppl = math.exp(val_loss)  
    elapsed = time.time() - epoch_start_time  

    print('-' * 89)
    print(f'| end of epoch {epoch:3d} | time: {elapsed:5.2f}s | '
          f'valid loss {val_loss:5.6f} | valid ppl {val_ppl:8.6f}')
    print('-' * 89)
    if epoch % 10 == 0:
        if epoch // 10 == 2:
            model_save_path = os.path.join(model_save_dir, 'epoch20shuff.pt')  
            best_model_state = copy.deepcopy(model.state_dict())
            torch.save(best_model_state, model_save_path)  
        if epoch // 10 == 3:
            model_save_path = os.path.join(model_save_dir, 'epoch30shufll.pt') 
            best_model_state = copy.deepcopy(model.state_dict())
            torch.save(best_model_state, model_save_path)  
        if epoch // 10 == 4:
            model_save_path = os.path.join(model_save_dir, 'epoch40shufll.pt')  
            best_model_state = copy.deepcopy(model.state_dict())
            torch.save(best_model_state, model_save_path)  
        if epoch // 10 == 5:
            model_save_path = os.path.join(model_save_dir, 'epoch50shufll.pt')  
            best_model_state = copy.deepcopy(model.state_dict())
            torch.save(best_model_state, model_save_path)  

