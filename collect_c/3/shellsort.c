#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 1000000
#define MAX_INT_DIGITS 11

void shellsort(int arr[], int n);

int main(int argc, char const *argv[])
{
	int c, i, j;
	char buf[MAX_INT_DIGITS+1];
	int arr[MAX_LEN];

	i = 0;
	j = 0;

	while ((c = getchar()) != EOF) {
		if (j >= MAX_LEN) {
			break;
		}

		if (isspace(c) && i > 0) {
			// flush the buf
			buf[i] = '\0';
			arr[j++] = atoi(buf);
			i = 0;
		} else if (isdigit(c) && i < MAX_INT_DIGITS) {
			buf[i++] = c;
		}
	}

	// flush the buf
	if (i > 0 && j < MAX_LEN) {
		buf[i] = '\0';
		arr[j++] = atoi(buf);
	}

	// sort the array
	shellsort(arr, j);

	for (i = 0; i < j; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

/* shellsort: sort an array in ascending order using Shell sorting algorithm */
void shellsort(int arr[], int n) {
	int i, j, k, temp;

	for (k = n/2; k > 0; k /= 2) { // decreasing step
		for (i = k; i < n; i += k) {
			for (j = i - k; j >= 0 && arr[j] > arr[j+k]; j -= k) {
				temp = arr[j];
				arr[j] = arr[j+k];
				arr[j+k] = temp;
			}
		}
	}
}


