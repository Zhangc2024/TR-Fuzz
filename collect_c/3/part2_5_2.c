/*
C Programming powerUp -Page 32
반지름 - 원넓게 게산
2016-06-26
*/

#include<stdio.h>

int main(void)
{
	fputs("반지름 입력 : ",stdout);
	double rad;
	scanf("%lf", &rad);
	printf("덧셈 : %lf \n", rad*rad*3.14);

	return 0;
}