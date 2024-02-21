/*
C Programming powerUp -Page 125
Dynamic Allocation
2016-06-26
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{

	char * str;
	str = (char*)malloc(sizeof(char) * 100);
	gets(str);
	puts(str);
	free(str);
	return 0;

}