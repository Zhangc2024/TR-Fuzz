/* c-examples by A.Shtanyuk */
/* digits.c - a digit array printing*/

#include <stdio.h>

void fun(int *arr)
{
	while(*arr)
		putchar(*arr++ +'0');
}

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,0};
	fun(arr);

	return 0;
}
