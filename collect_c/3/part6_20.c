/*
C Programming powerUp -Page 97
Call by Reference
2016-06-26
*/

#include <stdio.h>

void divInt(int*, int*, int*, int*);

int main(void) 
{

	int n1, n2;
	int result, mod;
	
	while (1)
	{
		fputs("나눗셈 위한 두 정수 입력 : ", stdout);
		scanf("%d %d", &n1, &n2);
		if (n2 != 0) break;
		puts("0으로 나누는 오류발생! 숫자 재입력");
	}

	divInt(&n1, &n2, &result, &mod);
	printf("목 : %d, 나머지 : %d \n", result,mod);


}

void divInt(int* n1, int *n2, int *result, int* mod) 
{
	*result=(*n1)/(*n2);
	*mod = (*n1) % (*n2);
}