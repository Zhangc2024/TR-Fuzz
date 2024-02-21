#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 			1000000
#define MAX_INT_DIGITS 	11
#define MAX_STACK_SIZE 	1000000

void merge_sort_rec(int arr[], int l, int r);
void merge_sort_stack(int arr[], int n);

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
	merge_sort_stack(arr, j);

	for (i = 0; i < j; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

/* merge_sort_rec: sort an array in ascending order using the merge sorting
   algorithm with a recursion, O(n*log(n)) time complexity and O(n) space 
   complexity */
void merge_sort_rec(int arr[], int l, int r) {
	if (l >= r) {
		return;
	}

	int i, j, k, mid;
	int temp[r - l + 1];

	mid = (l + r) / 2;
	merge_sort_rec(arr, l, mid);
	merge_sort_rec(arr, mid + 1, r);

	for (k = 0, i = l, j = mid + 1; k < (r - l + 1); ++k) {
		if (i > mid) {
			temp[k] = arr[j++];
		} else if (j > r) {
			temp[k] = arr[i++];
		} else if (arr[i] <= arr[j]) {
			temp[k] = arr[i++];
		} else {
			temp[k] = arr[j++];
		}
	}

	// copy sorted values back to the array
	for (i = l; i <= r; ++i) {
		arr[i] = temp[i-l];
	}
}

/* merge_sort_stack: sort an array in ascending order without a recursion */
void merge_sort_stack(int arr[], int n) {
	// using static to allocate bigger storage
	static int stack[MAX_STACK_SIZE][3];
	static int temp[MAX_LEN];

	int top[3];
	int i, j, k1, k2, mid;

	j = 0;
	i = 1;
	stack[0][0] = 0;
	stack[0][1] = n-1;
	stack[0][2] = 0;
	while (i > 0) { // while stack is not empty

		if (i > MAX_STACK_SIZE) {
			printf("stack overflow");
			exit(1);
		}

		// pop top indices
		top[0] = stack[i-1][0];
		top[1] = stack[i-1][1];
		top[2] = stack[i-1][2];

		if (top[0] >= top[1]) {
			// pop
			--i;
			continue;
		}

		mid = (top[0] + top[1]) / 2;
		if (top[2] == 1) {
			// already processed interval
			
			// merging two parts
			for (j = 0, k1 = top[0], k2 = mid + 1; j < (top[1] - top[0] + 1); ++j) {
				if (k1 > mid) {
					temp[j] = arr[k2++];
				} else if (k2 > top[1]) {
					temp[j] = arr[k1++];
				} else if (arr[k1] <= arr[k2]) {
					temp[j] = arr[k1++];
				} else {
					temp[j] = arr[k2++];
				}
			}

			// put it back into the array
			for (; j > 0; --j) {
				arr[top[0] + j - 1] = temp[j - 1];
			}

			// pop
			--i;
		} else {
			stack[i-1][2] = 1;

			// split interval into two parts and put into the stack
			stack[i][0] = top[0];
			stack[i][1] = mid;
			stack[i][2] = 0;
			++i;
			stack[i][0] = mid + 1;
			stack[i][1] = top[1];
			stack[i][2] = 0;
			++i;
		}
	}
}
