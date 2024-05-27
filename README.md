This is a fuzzer designed specifically for C compilers. 
It can generate a large number of C programs that meet the syntax requirements of C with Transformer model. 
For coverage collections in GCC and Clang/LLVM, we recommend using GCOV and LLVM-COV. For more details, please refer to the official documentations of GCC and LLVM.


To run TR-Fuzz, follow these steps:

1. Download the GCC test suite. (git clone https://github.com/gcc-mirror/gcc.git)
2. run data_prepare.py.
3. run model_train.py.
4. run model_generate.py.



You can use the GCC test suite alone to train and generate C programs, use the collected C programs, or combine both. If you want to use only the GCC test suite or the collected C programs, change the paths in the code to the path of the GCC test suite (located in the gcc/testsuite directory) or the path of the existing C programs. If you want to combine both, you need to modify the code in the training data selection part. (lines 25-30 in data_prepare.py and lines 254-260 in model_generate.py)






