/* c-examples by A.A.shtanyuk */
/* values.c - value, adress and size demo */

#include <stdio.h>

int main()
{
	int value=10;
	const float pi=3.14156;
	printf("VALUE:  Value=%d, Adress=%d, Size=%d\n",value,&value,sizeof(value));
	printf("PI:     Value=%f, Adress=%d, Size=%d\n",pi,&pi,sizeof(pi));
	return 0;
}
