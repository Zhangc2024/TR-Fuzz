/*
C Programming powerUp -Page 42
2���� ��ȯ
2016-06-26
*/

#include<stdio.h>

int main(void)
{
	int n,idx=0;
	int binary[100];

	fputs("10���� ���� �Է� : ", stdout);
	scanf("%d", &n);

	printf("%d�� 2������ ��ȯ�ϸ� : ", n);
	while (n> 0) {
		binary[idx++] = n % 2;
		n /= 2;
	}

	while (idx>0) {
		printf("%d", binary[--idx]);
	}
	printf("\n");
	return 0;
}