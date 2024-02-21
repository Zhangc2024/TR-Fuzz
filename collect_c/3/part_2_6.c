/*
C Programming powerUp -Page 32
형변환
2016-06-26
*/

#include<stdio.h>

int main(void)
{
	int temp;
	int i,max=-100000000,min=1000000000,tot=0;

	for (i = 0; i < 7; i++) {
		fputs("정수형 데이터 입력 : ", stdout);
		scanf("%d", &temp);

		if (temp > max) max = temp;
		if (temp < min) min = temp;
		tot += temp;

	}
	
	printf("최대값 : %d \n", max);
	printf("최소값 : %d \n", min);
	printf("전체합 : %d \n", tot);
	printf("평균 : %lf \n", (double)tot/7);

	return 0;
}