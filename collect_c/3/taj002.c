#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main ()
{
	char text[100];
	printf("Matnni kiriting: ");
	scanf("%s", text);
	int belgi=0, i;
	for (i=0; i<strlen(text); i++)
	{
		if (isupper(text[i]))
		{ belgi++; }
	}
	printf("Kiritilgan matnda %d ta maxsus belgi bor\n", belgi);
	return 0;
}