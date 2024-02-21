/*
C Programming powerUp -Page 52
continue 문제
2016-06-26
*/

#include<stdio.h>

int main(void)
{
	int n1, n2,i,tot=0;


	fputs("두 개의 정수 입력 : ", stdout);
	scanf("%d %d", &n1,&n2);

	if (n1 > n2) {
		i = n1;
		n1 = n2;
		n2 = i;
	}

	for (i = n1; i <= n2; i++) {
		if (i % 3 == 0 || i%5==0) {
			printf("%d는 합에서 제외 \n", i);
		}else tot += i;
	}

	printf("%d와 %d를 포함하여 그 사이에 있는 정수들의 합 : %d \n",n1,n2,tot);
}