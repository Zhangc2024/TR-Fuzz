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
		puts("���� 'character.txt'�� ������ �ʾҽ�����.");
		return -1;
	}

	fputs("����� ������ ������ ??",stdout);
	scanf("%d", &len);

	for (i = 0; i < len;i++)
	{
		ch = fgetc(fp);
		if (ch == EOF) 
		{
			puts("������ ���� �����Ͽ����ϴ�.");
			return -1;
		}
		printf("%c", ch);
	}

	fclose(fp);
	puts("");
	puts("����� �Ϸ�Ǿ����ϴ�.");
	


	return 0;
}