/*
C Programming powerUp -Page 210
File
2016-06-27
*/

#include <stdio.h>

int main(void) 
{

	char writeChar[] = "�����ٶ󸶹ٻ������īŸ����";
	int i;

	FILE *fp = fopen("character.txt","w");
	if (fp == NULL) 
	{
		puts("���� 'character.txt'�� ������ �ʾҽ��ϴ�.");
		return -1;
	}

	for (i = 0 ; i < sizeof(writeChar)-1; i++) 
	{
		fputc(writeChar[i], fp);
	}

	fputs(writeChar,fp);

	fclose(fp);
	puts("�Է��� �Ϸ�Ǿ����ϴ�.");

	return 0;
}