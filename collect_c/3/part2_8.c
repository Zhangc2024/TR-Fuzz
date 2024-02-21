/*
C Programming powerUp -Page 42
2진법 변환
2016-06-26
*/

#include<stdio.h>

int main(void)
{
	int n,idx=0;
	int binary[100];

	fputs("10진수 정수 입력 : ", stdout);
	scanf("%d", &n);

	printf("%d를 2진수로 변환하면 : ", n);
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