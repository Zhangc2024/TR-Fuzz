#include<stdio.h>
main()
{
	printf("value of EOF %x\n", EOF);
	int c;
	while (c=getchar()){
        if (c != '\n')
        printf("%x.\n",c);
	}
}
