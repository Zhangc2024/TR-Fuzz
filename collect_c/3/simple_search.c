#include <stdio.h>

#define ARRAY_SIZE 100

int simple_search(int arr[], int item);

int main(void) {
	int array[ARRAY_SIZE];
	int search_item;
	int result;

	for (int i = 0; i < ARRAY_SIZE; i++) {
		array[i] = i;
	}

	printf("What number would you like to find?\n");
	scanf("%d", &search_item, stdin);

	result = simple_search(array, search_item);

	if (result == -1)
		printf("Item not found.\n");
	else
		printf("Item found at index %d.\n", result);

	return 0;
}

int simple_search(int arr[], int item)
{
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (arr[i] == item)
			return i;
	}
	return -1;
}
