/*
C Programming powerUp -Page 52
continue ����
2016-06-26
*/

#include<stdio.h>

int main(void)
{
	int n1, n2,i,tot=0;


	fputs("�� ���� ���� �Է� : ", stdout);
	scanf("%d %d", &n1,&n2);

	if (n1 > n2) {
		i = n1;
		n1 = n2;
		n2 = i;
	}

	for (i = n1; i <= n2; i++) {
		if (i % 3 == 0 || i%5==0) {
			printf("%d�� �տ��� ���� \n", i);
		}else tot += i;
	}

	printf("%d�� %d�� �����Ͽ� �� ���̿� �ִ� �������� �� : %d \n",n1,n2,tot);
}