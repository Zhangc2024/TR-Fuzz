/*
C Programming powerUp -Page 61
for�� ��ø - ������ ���
2016-06-26
*/

#include<stdio.h>

int main(void)
{
	int choice,i,j;

	fputs("Ȧ�� ��(1), ¦�� ��(2) :",stdout);
	while (1) {
		scanf("%d", &choice);
		if (choice == 1 || choice == 2) break;
		fputs("�߸��� �Է��Դϴ�. 1�Ǵ� 2�� �Է��ϼ���\n",stdout);
	}
	for (i = 2; i <= 9;i++) {
		if (choice == 1 && i % 2 == 0)  continue;
		else if (choice == 2 && i % 2 == 1) continue;

		for (j = 1; j <= 9;j++) {
			printf("%d x %d = %d \n", i,j,i*j);
		}
	}
	
}