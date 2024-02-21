#include <stdio.h>
int main()
{
	int numbers[100], n;
	int i;
	printf("n="); scanf("%d", &n);
	printf("Seriya elementlarini kiriting: ");
	
	for (i=0; i<n; i++)
	{
		scanf("%d", &numbers[i]);	
	}
	
	printf("Juft qiymatli elementlar: ");
	for (i=0; i<n; i++)
	{
		if (numbers[i]%2==0)
		printf("%d ", numbers[i]);
	}
	printf("\nToq indeksdagi qiymatlar: ");
	for (i=1; i<n; i+=2)
	{
		printf("%d ", numbers[i]);
	}
	printf("\n");
	return 0;
}