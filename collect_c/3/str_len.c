/* c-examples by A.A.Shtanyuk */
/* str_len.c  - the length of string */

#include <stdio.h>

int length(char *s)
{
  int i = 0;
  while (*s && (*s++!='\n'))
    i++;
  return i;
}

int main()
{
	char buf[80];
	puts("Enter a string:");
	fgets(buf,80,stdin);
    printf("The length of string is %d\n",length(buf));
    return 0;	
}