/*
C Programming powerUp -Page 47
if~else, while, for, break ����
2016-06-26
*/

#include<stdio.h>

int main(void)
{
	int n;
	int tot = 1;
	fputs("1 �̻��� ���� �Է� :",stdout);
	while(1){
		scanf("%d", &n);
		if (n > 0) break;
		else puts("1 �̻��� ������ �Է��ؾ� �մϴ�.",stdout);
	}

	while (n>0) {
		tot += n--;
	}
	printf("�� ���� : %d \n", tot);

	


}