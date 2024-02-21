#include <stdio.h>

void selection_sort(int arr[], int start, int len);

int main(void)
{
	int i;
	int array[] = {7, 2, 3, 5, 1, 0, 9, 8, 4, 6};
	int len = sizeof(array) / sizeof(int);

	for (i = 0; i < len; i++) {
		selection_sort(array, i, len);
	}

	printf("Sorted:");
	for (i = 0; i < len; i++) {
		printf(" %d", array[i]);
	}
	printf("\n");

	return 0;
}

void selection_sort(int arr[], int start, int len)
{
	int lowest_value = arr[start];
	int lowest_index = start;
	int tmp;

	for (int j = start; j < len; j++) {
		if (arr[j] < lowest_value) {
			lowest_value = arr[j];
			lowest_index = j;
		}
	}

	tmp = arr[start];
	arr[start] = lowest_value;
	arr[lowest_index] = tmp;
}
