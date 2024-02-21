#include <stdio.h>

#define ARRAY_SIZE 100

int binary_search(int arr[], int item);

int main(void) {
	int array[ARRAY_SIZE];
	int search_item;
	int result;

	for (int i = 0; i < ARRAY_SIZE; i++) {
		array[i] = i;
	}

	printf("What number would you like to find?\n");
	scanf("%d", &search_item, stdin);

	result = binary_search(array, search_item);

	if (result == -1)
		printf("Item not found.\n");
	else
		printf("Item found at index %d.\n", result);

	return 0;
}

int binary_search(int arr[], int item)
{
	int low;
	int high;
	int mid;

	low = 0;
	high = ARRAY_SIZE;

	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] == item) {
			return mid;
		} else if (arr[mid] > item) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
		
	}

	return -1;
}
