#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#define MAX_BUF 12
#define MAX_LEN 1000000

int binsearch(int x, int a[], int n);

int main(int argc, char const *argv[])
{
	int i, n, c, x, res;
	char buf[MAX_BUF];
	int arr[MAX_LEN];

	assert(argc > 1);
	x = atoi(argv[1]);

	i = 0;
	while ((c = getchar()) != EOF) {
		if (n >= MAX_LEN) {
			break;
		}

		if (isspace(c)) {
			// flush
			buf[i] = '\0';
			arr[n++] = atoi(buf);
			i = 0;
		} else if (i < MAX_BUF - 1) {
			buf[i++] = c;
		}
	}

	if (i > 0) {
		// flush
		buf[i] = '\0';
		arr[n++] = atoi(buf);
	}

	res = binsearch(x, arr, n);
	if (res < 0) {
		printf("%d has not been found\n", x);
	} else {
		printf("%d has been found at position %d\n", x, res);
	}

	return 0;
}

int binsearch(int x, int a[], int n) {
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low < high) {
		mid = (low + high) / 2;
		if (x <= a[mid]) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}

	if (a[low] == x) {
		return low;
	}

	return -1;
}
