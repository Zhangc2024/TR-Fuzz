/*
C Programming powerUp -Page 111
Function with String
2016-06-26
*/



#include<stdio.h>

int strLen(char* str) 
{
	int len = 0;
	while (str[len++] != '\0');

	return len-1;

}


int strCpy(char* dest, char* source) 
{

	int len = strLen(source) + 1;
	int i;

	for (i = 0; i < len; i++) 
	{
		dest[i] = source[i];
	}

	return len;

}

int strCat(char* dest, char*source) 
{
	int len = strLen(dest);
	int Slen = strLen(source) + 1;
	int i;

	for (i = 0; i < Slen; i++) dest[i+len] = source[i];

	return len + Slen;
}



int main(void ) 
{

	char st1[100], st2[100];
	puts("문자열 2개를 입력해 주세요");
	gets(st1);
	gets(st2);
	strCat(st1, st2);
	printf("%s \n", st1);

	return 0;
}
