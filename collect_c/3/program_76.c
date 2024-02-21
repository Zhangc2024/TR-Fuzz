// find largest number in the array of floating point numbers using dynamic memory allocation

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n;
	float *data;

	printf("Please enter the number of values: ");
	scanf("%d", &n);

	data = (float *)calloc(n, sizeof(float));
	if (data == NULL)
	{
		printf("ERROR! memory allocation failed.\n");
		exit(0);
	}

	printf("Please enter the values:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%f", data + i);
	}

	for (i = 1; i < n; i++)
	{
		if (*data < *(data + i))
		{
			*data = *(data + i);
		}
	}
	printf("Largest number is %f.\n", *data);

	return 0;
}
