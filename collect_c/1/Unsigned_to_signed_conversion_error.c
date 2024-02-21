#include <stdio.h>
int main() {
int value;
value = (int)(~((int)0) ^ (1 << (sizeof(int)*8)));
printf("Max unsigned int: %u %1$x\nNow signed: %1$d %1$x\n",
value);
return(0);

/*
The above code produces the following output:
Max unsigned int: 4294967295 ffffffff
Now signed: -1 ffffffff

Note how the hex value remains unchanged.

*/}







