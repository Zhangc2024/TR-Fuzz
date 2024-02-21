/*
C Programming powerUp -Page 61
for문 중첩 - 구구단 출력
2016-06-26
*/

#include<stdio.h>

int main(void)
{
	int choice,i,j;

	fputs("홀수 단(1), 짝수 단(2) :",stdout);
	while (1) {
		scanf("%d", &choice);
		if (choice == 1 || choice == 2) break;
		fputs("잘못된 입력입니다. 1또는 2만 입력하세요\n",stdout);
	}
	for (i = 2; i <= 9;i++) {
		if (choice == 1 && i % 2 == 0)  continue;
		else if (choice == 2 && i % 2 == 1) continue;

		for (j = 1; j <= 9;j++) {
			printf("%d x %d = %d \n", i,j,i*j);
		}
	}
	
}