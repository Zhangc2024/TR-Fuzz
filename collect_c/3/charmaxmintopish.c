#include <stdio.h>
int main()
{
	int A[10];
	printf("10 elementdan iborat seriyani kiriting: ");
	
	for (int i=0; i<10; i++)
	{
		scanf("%d", &A[i]);
	}
	
	int max=A[0], min=A[0];
	for (int i=1; i<10; i++)
	{
		if (A[i]>max)
		{
			max=A[i];
		}
		if (A[i]<min)
		{
			min=A[i];
		}
	}
	printf("max=%d\tmin=%d\n", max, min);
	
	return 0;
}
