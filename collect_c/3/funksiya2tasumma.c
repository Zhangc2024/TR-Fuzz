#include <stdio.h>
int summa(int a, int b)
{
	int s=a+b;
	return s;
}
int main()
{
	int yigindi=summa(10,5);
	printf("\nYig'indi=%d\n", yigindi);
	int son1, son2;
	printf("\n2 ta sonni kiriting: ");
	scanf("%d%d", &son1, &son2);
	printf("\n%d+%d=%d", son1, son2, summa(son1, son2));
	return 0;
}