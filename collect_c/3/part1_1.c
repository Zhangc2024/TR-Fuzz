#include<stdio.h>

int main(void) 
{

	char c;
	int n;
	float f;
	char s[10];
	
	printf("[����, ����,  �Ǽ�, ���ڿ�]�� �������� �Է�");
	scanf("%c, %d, %f, %s",&c,&n,&f,s);

	printf("�Էµ� ������ ��� : %c, %d, %f, %s \n", c,n,f,s);

	return 0;
}