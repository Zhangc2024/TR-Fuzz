/* c-examples by A.Shtanyuk */
/* pangramm.c - Which chars are in the string? */

#include <stdio.h>
#define N 256

void chomp(char *str)
{
	if(str[strlen(str)-1]=='\n')
		str[strlen(str)-1]=0;
}

int main()
{
	int count[N]={0};
	unsigned char str[N];
	int i=0;

    puts("Hello, enter a string:");
	fgets(str,N,stdin);
	chomp(str);

	while(str[i])
		count[str[i++]]++;
	for(i=0;i<N;i++)
		if(count[i]>0)
			putchar(i);
	putchar('\n');
	return 0;
}
