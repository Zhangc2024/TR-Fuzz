/* c-examples by A.A.Shtanyuk */
/* str_inv - string inversion */

#include <stdio.h>
#include <string.h>

int chomp(char *buf)
{
	int len=strlen(buf);
	if(buf[len-1]=='\n')
		buf[--len]=0;
	return --len; // last char position
}

int main()
{
	char string[256];
	int top=0, bot=0;
	char temp;
    puts("Enter a string, please: ");
    fgets(string,256,stdin);

	for (bot=chomp(string); top < bot ; top++, bot--)
	{
		temp=string[top];
		string[top]=string[bot];
		string[bot]=temp;
	}
	puts(string);
	return 0;
}
