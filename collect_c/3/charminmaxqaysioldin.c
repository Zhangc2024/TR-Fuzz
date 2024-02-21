#include <stdio.h>
int main()
{
	int A[10];
	int i;
	printf("10 elementdan iborat seriyani kiriting: ");
	
	for (i=0; i<10; i++)
	{
		scanf("%d", &A[i]);
	}
	
	int max=A[0], min=A[0], imax=0, imin=0; 
	for (i=1; i<10; i++)
	{
		if (A[i]>max)
		{
			max=A[i];
            imax=i;
		}
		if (A[i]<min)
		{
			min=A[i];
            imin=i;
		}
	}
	if (imax<imin)
    { printf("max min dan oldin\n"); }
	
	else if (imin<imax)
	{ printf("min maxdan oldin\n");}
	
	else
	{ printf("Sonlar bir xil\n");}
	return 0;
}