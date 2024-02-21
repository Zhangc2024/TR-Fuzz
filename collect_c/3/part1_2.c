#include <stdio.h>
#define MAX_LEN 50

int main() 
{
	char s[MAX_LEN];

	//printf("문자열 입력 : ");
	fputs("문자열 입력 : ", stdout);
	gets(s);

	//printf("입력된 문자열 : %s" ,s);
	fputs("입력된 문자열 :", stdout);
	puts(s);


	return 0;
}
