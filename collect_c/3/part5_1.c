/*
C Programming powerUp -Page 75
������ ���� �з�
2016-06-26
*/

#include<stdio.h>

int main(void)
{

	char cur;

	while (1) {
		
		cur=getchar();
		fflush(stdin);
		if (cur >= 'a' && cur <= 'z') puts("�Է��Ͻ� ���ڴ� ���ĺ� �ҹ����Դϴ�.");
		else if (cur >= 'A' && cur <= 'Z') puts("�Է��Ͻ� ���ڴ� ���ĺ� �빮���Դϴ�.");
		else if (cur >= '0' && cur <= '9') puts("�Է��Ͻ� ���ڴ� �ƶ��� �����Դϴ�.");
		else if (cur == EOF) break;
		else puts("Ư�� ���ڸ� �Է��ϼ̱���.");
		
	}
	puts("���α׷��� �����մϴ�.");
}