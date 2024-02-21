/* c-examples by A.A.Shtanyuk */
/* sizeofv.c - size of data type */

#include <stdio.h>

int main()
{
  printf("Size of data type:\n"); 
  printf("char - %d\n",sizeof(char));
  printf("short - %d\n",sizeof(short));
  printf("int - %d\n",sizeof(int));
  printf("long - %d\n",sizeof(long));
  printf("float - %d\n",sizeof(float));
  printf("double - %d\n",sizeof(double));
  printf("long double - %d\n",sizeof(long double));
  printf("long long - %d\n",sizeof(long long));   // C99!

  return 0;
}
