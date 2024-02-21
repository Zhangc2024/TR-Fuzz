/* c-examples by A.Shtanyuk */
/* word_len.c - split a string into words */

#include <stdio.h>
#include <string.h>
#define N 256

void chomp(char *str)
{
	if(str[strlen(str)-1]=='\n')
		str[strlen(str)-1]=0;
}
int main()
{
	char str[N];
	short inWord=0;
	int len=0,i=0;

	puts("Hello, enter a string:");
	fgets(str,N,stdin);
	chomp(str);

	while(str[i])
	{
		if(str[i]!=' ' && inWord==0)
		{
			// word begins
			inWord=1;
			len++;
			putchar(str[i]);
		}
		else if(str[i]!=' ' && inWord==1)
		{
			// inside word
			len++;
			putchar(str[i]);
		}
		else if(str[i]==' ' && inWord==1)
		{
			// word ends
			printf("-%d\n",len);
			len=0;
			inWord=0;
		}
		i++;
	}
	if(inWord==1)
	  printf("-%d\n",len);
	return 0;
}
