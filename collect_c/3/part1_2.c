#include <stdio.h>
#define MAX_LEN 50

int main() 
{
	char s[MAX_LEN];

	//printf("���ڿ� �Է� : ");
	fputs("���ڿ� �Է� : ", stdout);
	gets(s);

	//printf("�Էµ� ���ڿ� : %s" ,s);
	fputs("�Էµ� ���ڿ� :", stdout);
	puts(s);


	return 0;
}
