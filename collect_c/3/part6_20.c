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
		fputs("������ ���� �� ���� �Է� : ", stdout);
		scanf("%d %d", &n1, &n2);
		if (n2 != 0) break;
		puts("0���� ������ �����߻�! ���� ���Է�");
	}

	divInt(&n1, &n2, &result, &mod);
	printf("�� : %d, ������ : %d \n", result,mod);


}

void divInt(int* n1, int *n2, int *result, int* mod) 
{
	*result=(*n1)/(*n2);
	*mod = (*n1) % (*n2);
}