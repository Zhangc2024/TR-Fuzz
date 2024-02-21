// print sum and average of numbers using array

#include <stdio.h>

int main()
{
	int i, n;

	float num[100], sum = 0.0, avg;

	printf("Please enter the number of values: ");
	scanf("%d", &n);

	while (n > 100 || n < 1)
	{
		printf("Error! The number should in range of 1 to 100.\n");
		printf("Enter the number of values: ");
		scanf("%d", &n);
	}

	for (i = 0; i < n; i++)
	{
		printf("%d. Enter number: ", i + 1);
		scanf("%f", &num[i]);
		sum += num[i];
	}

	avg = sum / n;

	printf("Average = %f, Sum = %f.\n", avg, sum);

	return 0;
}
