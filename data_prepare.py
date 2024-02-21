import random
import re
from subprocess import Popen, PIPE, STDOUT
import os
from data_preprocess import replace_macro, remove_space, remove_comment, verify_correctness


def generate_training_data(text):
	maxlen = 50
	sentences = []
	traget_sentences = []
	next_chars = []
	if len(text) > 51:
		for i in range(0, len(text) - maxlen - 1):
			sentences.append(text[i: i + maxlen])
			next_chars.append(text[i + maxlen])
			sentences[i] = re.sub(r'[\n\t]', ' ', sentences[i])
			next_chars[i] = re.sub(r'[\n\t]', ' ', next_chars[i])
			print(sentences[i] + "\t" + next_chars[i], file=open('./testsuit/train_data', 'a+', encoding='iso-8859-1'))
		return 1
	else:
		return 0


files = []
valid_count = 0
path = './gcc/gcc/testsuite'
for root, d_names, f_names in os.walk(path):
	for f in f_names:
		files.append(os.path.join(root, f))
for file in files:
	if ('nocomment' in file or 'nospace' in file or 'nomacro' in file or 'raw' in file):
		command = 'rm ' + file
		p = Popen(command, shell=True, stdin=PIPE, stdout=PIPE, stderr=STDOUT, close_fds=True)
		continue
	if (not file.endswith('.c') and not file.endswith('.h') and not file.endswith('.C')):
		continue
	text = open(file, 'r', encoding='iso-8859-1').read()
	text = remove_comment(text)
	text = replace_macro(text, file)
	text = remove_space(text)
	is_valid = verify_correctness(text, file, 'nospace')
	if (is_valid):
		if valid_count < 10000:
			if (generate_training_data(text)) == 1:
				valid_count += 1
		else:
			break  
print(valid_count)
