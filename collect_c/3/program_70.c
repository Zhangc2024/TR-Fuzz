// print the largest value in an array

#include <stdio.h>

int main()
{
	int arr[10], i, max;

	printf("Please enter ten numbers: ");

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}

	max = arr[0];
	for (i = 1; i < 10; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	printf("Largest number in the array is %d.\n", max);

	return 0;
}
