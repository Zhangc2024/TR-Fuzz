/*
C Programming powerUp -Page 32
����ȯ
2016-06-26
*/

#include<stdio.h>

int main(void)
{
	int temp;
	int i,max=-100000000,min=1000000000,tot=0;

	for (i = 0; i < 7; i++) {
		fputs("������ ������ �Է� : ", stdout);
		scanf("%d", &temp);

		if (temp > max) max = temp;
		if (temp < min) min = temp;
		tot += temp;

	}
	
	printf("�ִ밪 : %d \n", max);
	printf("�ּҰ� : %d \n", min);
	printf("��ü�� : %d \n", tot);
	printf("��� : %lf \n", (double)tot/7);

	return 0;
}