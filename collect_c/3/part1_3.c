#include <stdio.h>

int main(void) {

	int n1, n2, result;

	fputs("두 수를 16진수로 입력 : ", stdout);
	scanf("%x %x", &n1, &n2);
	result = n1 + n2;

	printf("연산 결과 8진수 : %o \n", result);
	printf("연산 결과 10진수 : %d \n", result);
	printf("연산 결과 16진수 : %x \n", result);




	return 0;
}