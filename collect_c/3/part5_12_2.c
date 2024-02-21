/*
C Programming powerUp -Page 61
for문 중첩 - a*b-c=n 풀기
2016-06-26
*/

#include<stdio.h>

int main(void)
{
	int n;
	int a, b, c;

	fputs("정수 입력 : ",stdout);
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