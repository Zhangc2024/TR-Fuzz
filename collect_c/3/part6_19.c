/*
C Programming powerUp -Page 93
�Լ� �⺻
2016-06-26
*/

#include <stdio.h>

int factorial(int n) 
{
	if (n < 2) return 1;
	else return n*factorial(n - 1);
}
int main(void) {

	int n;
	fputs("���� �Է�(1�̻�) : ", stdout);
	scanf("%d", &n);
	
	printf("%d! = %d \n", n, factorial(n));

	return 0;
}