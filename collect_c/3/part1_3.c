#include <stdio.h>

int main(void) {

	int n1, n2, result;

	fputs("�� ���� 16������ �Է� : ", stdout);
	scanf("%x %x", &n1, &n2);
	result = n1 + n2;

	printf("���� ��� 8���� : %o \n", result);
	printf("���� ��� 10���� : %d \n", result);
	printf("���� ��� 16���� : %x \n", result);




	return 0;
}