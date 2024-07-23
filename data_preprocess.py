import numpy as np
import os
import time
import re
from subprocess import Popen, PIPE, STDOUT
# we save the C programs generated by the model to this path
bug_dir = ''
if not os.path.exists(bug_dir):
    os.makedirs(bug_dir)


def remove_comment(text):         
    def replacer(match):
        s = match.group(0)        
        if s.startswith('/'):      
            return " " # note: a space and not an empty string 
        else:
            return s             

    pattern = re.compile(
        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
        re.DOTALL | re.MULTILINE

    )
    return re.sub(pattern, replacer, text)   


def verify_correctness(text, filename, mode):
    name = filename[:-2]                        
    postfix = filename[-2:]                      
    filename = name + '_' + mode + postfix       
    f = open(filename, 'w', encoding='iso-8859-1')                     

    index = filename.rfind('/') + 1
    obj_name = filename[index:-2]
    command = 'gcc -c -w ' + filename + ' -o ./compile_build/' + obj_name + '.o'

    f.write(text)                               
    f.close()   # @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    p1 = Popen(command, shell=True, stdin=PIPE, stdout=PIPE, stderr=STDOUT, close_fds=True)  。

    stderr = str(p1.stdout.read())
    print(stderr)
    # if ('internal compiler error' in stderr):     
    #     return True
    # if ('error' in stderr):
    #     return False
    # else:
    #     return True


def generate_verify_correctness(text, filename, mode):
    name = filename[:-2]                        
    postfix = filename[-2:]                     
    filename = name + '_' + mode + postfix      
    f = open(filename, 'w', encoding='iso-8859-1')                    
    index = filename.rfind('/') + 1
    get_name = filename[index:]
    obj_name = filename[index:-2]

    command = 'gcc -c -w ' + filename + ' -o ./compile_build/' + obj_name + '.o'
    f.write(text)                             
    f.close()
    p1 = Popen(command, shell=True, stdin=PIPE, stdout=PIPE, stderr=STDOUT, close_fds=True)  
    if 'g1' in mode:
        generate_path = './testsuit/generate/g1/'
    elif 'g2' in mode:
        generate_path = './testsuit/generate/g3/'
    else:
        generate_path = './testsuit/generate/g3/'
    os.makedirs(generate_path, exist_ok=True)
    with open(os.path.join(generate_path, get_name), 'w', encoding='iso-8859-1') as wf:
        wf.write(text)

    stderr = str(p1.stdout.read())
    print(stderr)
    if ('internal compiler error' in stderr):  
        bug_filename = bug_dir + 'bug_' + str(int(time.time_ns())) + '.c'
        with open(bug_filename, 'w') as bug_file:
            bug_file.write(text)
        return True
    if ('error' in stderr):
        return False
    else:
        return True


def replace_macro(text, filename):               
    headers = re.findall(r'#include .*\n', text)
    text = re.sub(r'#include .*\n', '', text)    
    postfix = filename[-2:]                      
    tempfile = 'temp' + postfix                  
    print(text, file=open(tempfile, 'w',encoding='iso-8859-1'))   
    command = 'gcc -E ' + tempfile + ' > temp'   
    p = Popen(command, shell=True, stdin=PIPE, stdout=PIPE, stderr=STDOUT, close_fds=True)  
    text = open(tempfile, 'r',encoding='iso-8859-1').read()  
    text = re.sub(r'#\D+ .*\n', '', text)               
    for header in headers:
        text = header + text                    
    return text


def remove_space(text):                         
    text = re.sub(r'\n', ' ', text)
    text = re.sub(r'\s', ' ', text)
    text = re.sub(r'\\t', ' ', text)
    text = re.sub(r' +', ' ', text)
    return text
