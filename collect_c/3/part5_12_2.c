/*
C Programming powerUp -Page 61
for�� ��ø - a*b-c=n Ǯ��
2016-06-26
*/

#include<stdio.h>

int main(void)
{
	int n;
	int a, b, c;

	fputs("���� �Է� : ",stdout);
	scanf("%d", &n);

	for (a = 0; a <= 100;a++) {
		for (b = 0; b <= 100; b++) {
			for (c = 0; c <= 100; c++) {
				if (a*b - c == n) {
					printf("%d x %d -%d = %d\n", a,b,c,n);
				}
			}
		}
	}



}