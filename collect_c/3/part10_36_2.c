/*
C Programming powerUp -Page 210
File
2016-06-27
*/


#include<stdio.h>


int main(void)
{

	FILE *fp = fopen("character.txt","r");
	int i,len;
	char ch;

	if (fp == NULL)
	{
		puts("파일 'character.txt'가 열리지 않았습ㄴ디ㅏ.");
		return -1;
	}

	fputs("출력할 문자의 갯수는 ??",stdout);
	scanf("%d", &len);

	for (i = 0; i < len;i++)
	{
		ch = fgetc(fp);
		if (ch == EOF) 
		{
			puts("파일의 끝에 도달하였습니다.");
			return -1;
		}
		printf("%c", ch);
	}

	fclose(fp);
	puts("");
	puts("출력이 완료되었습니다.");
	


	return 0;
}