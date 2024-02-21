/*
C Programming powerUp -Page 219
File
2016-06-27
*/
#include<stdio.h>

int main(void)
{

	int i;
	char str[100];


	FILE *fp = fopen("string.txt","w+");
	if (fp == NULL)
	{
		puts("파일 string.txt가 열리지 않았습니다");
		return -1;
	}

	for (i = 0; i < 5; i++) 
	{
		fgets(str,99,stdin);
		fputs(str, fp);
	}
	
	fseek(fp, 0, SEEK_SET);
	
	for (i = 0; i < 5; i++)
	{
		fgets(str, 99, fp);
		puts(str);
	}
	


	return 0;
}