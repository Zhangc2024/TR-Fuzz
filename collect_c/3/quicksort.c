#include <stdio.h>
#include <stdlib.h>

void quicksort(int arr[], int len);

int main(void)
{
	int array[] = {4, 1, 2, 9, 5, 8, 7, 3, 6, 0};
	int len = sizeof(array) / sizeof(int);

	quicksort(array, len);

	printf("Sorted:");
	for (int i = 0; i < len; i++) {
		printf(" %d", array[i]);
	}
	printf("\n");

	return 0;
}

void quicksort(int arr[], int len)
{
	// First Base Case
	if (len < 2) {
		return;
	}

	// Second Base Case
	if (len == 2) {
		if (arr[0] > arr[1]) {
			int tmp = arr[0];
			arr[0] = arr[1];
			arr[1] = tmp;
			return;
		} else {
			return;
		}
	}

	// Recursive Case
	int i, j, k;
	int p_index = rand() % len;
	int p_value = arr[p_index];
	int less_arr[len];
	int more_arr[len];
	int less_len;
	int more_len;

	// Use pivot value to divide starting array into lower and higher arrays
	for (i = j = k = 0; i < len; i++) {
		if (i == p_index) {
			continue;
		} else if (arr[i] < p_value) {
			less_arr[j++] = arr[i];
			less_len = j;
		} else {
			more_arr[k++] = arr[i];
			more_len = k;
		}
	}

	// Call quicksort on lower and higher arrays
	quicksort(less_arr, less_len);
	quicksort(more_arr, more_len);

	// Combine sorted results back into starting array
	for (i = 0; i < less_len; i++) {
		arr[i] = less_arr[i];
	}

	arr[less_len] = p_value;

	for (i = 0, j = less_len + 1; i < more_len; i++) {
		arr[j++] = more_arr[i];
	}

	return;
}
