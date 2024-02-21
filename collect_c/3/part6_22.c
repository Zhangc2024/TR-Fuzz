/*
C Programming powerUp -Page 97
Function with String
2016-06-26
*/


#include <stdio.h>
#define MAX_LEN 100


int ChaNumOfString(char*, char);


int main(void) 
{

	char str[MAX_LEN];
	char cmp;
	fputs("대상 문자열 입력 : ",stdout);
	gets(str);
	fputs("세어 볼 문자 입력 : ",stdout);
	cmp=getchar();

	printf("%c의 개수 : %d \n", cmp, CharNumOfString(str,cmp));


	return 0;
}

int CharNumOfString(char* str, char cmp)
{
	int sum = 0;
	int i = 0;
	while (str[i]!='\0') 
	{
		if (str[i++] == cmp) sum++;
	}



	return sum;

}
