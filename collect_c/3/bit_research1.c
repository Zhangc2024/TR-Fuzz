/* c-examples by A.A.Shtanyuk */
/* bit_research1.c  - work with bits */

#include <stdio.h>
union CODE  
{
	unsigned char ch;
	struct BYTE
	{
		unsigned char b1:1;
		unsigned char b2:1;
		unsigned char b3:1;
		unsigned char b4:1;
		unsigned char b5:1;
		unsigned char b6:1;
		unsigned char b7:1;
		unsigned char b8:1;
	} byte;
};

void bin(unsigned char c) 
	union CODE code;
	code.ch=c;
	printf("%d %d %d %d %d %d %d %d    \n",
		code.byte.b8,
		code.byte.b7,
		code.byte.b6,
		code.byte.b5,
		code.byte.b4,
		code.byte.b3,
		code.byte.b2,
		code.byte.b1);
	
}

int main()
{
	int a=5;
	int d=31;
	int b=a | (1<<d);
	bin(a);
	printf("%d,%d\n",a,b);
	return 0;
}

