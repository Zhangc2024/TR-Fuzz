/*
C Programming powerUp -Page 47
if~else, while, for, break 문제
2016-06-26
*/

#include<stdio.h>

int main(void)
{
	int n;
	int tot = 1;
	fputs("1 이상의 정수 입력 :",stdout);
	while(1){
		scanf("%d", &n);
		if (n > 0) break;
		else puts("1 이상의 정수를 입력해야 합니다.",stdout);
	}

	while (n>0) {
		tot += n--;
	}
	printf("총 합은 : %d \n", tot);

	


}