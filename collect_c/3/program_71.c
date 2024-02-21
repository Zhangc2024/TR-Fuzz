// find the standard deviation of a data

#include <stdio.h>
#include <math.h>

float getSD(float data[])
{
	float sum = 0.0, mean, SD = 0.0;
	int i;

	for (i = 0; i < 10; i++)
	{
		sum += data[i];
	}

	mean = sum / 10;

	for (i = 0; i < 10; i++)
	{
		SD += pow(data[i] - mean, 2);
	}
	return sqrt(SD / 10);
}

int main()
{
	int i;
	float data[10];

	printf("Please enter data:\n");

	for (i = 0; i < 10; i++)
	{
		scanf("%f", &data[i]);
	}

	printf("Standard deviation is: %f.\n", getSD(data));
	return 0;
}
