#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 1000000
#define BUFSIZE 11

void q_sort(int a[], int l, int r);

int main(int argc, char const *argv[])
{
	int i, c, j;
	int arr[MAXSIZE];
	char buf[BUFSIZE+1];
	int bufp;
	
	i = 0;
	bufp = 0;
	while ((c = getchar()) != EOF) {
		if (i >= MAXSIZE) {
			break;
		}

		if (isspace(c) && bufp > 0) {
			buf[bufp] = '\0';
			arr[i++] = atoi(buf);
			bufp = 0;
		} else if (bufp < BUFSIZE) {
			buf[bufp++] = c;
		}
	}

	if (bufp > 0 && i < MAXSIZE) {
		buf[bufp] = '\0';
		arr[i++] = atoi(buf);
	}

	q_sort(arr, 0, i-1);

	for (j = 0; j < i; ++j) {
		printf("%d ", arr[j]);
	}
	printf("\n");

	return 0;
}

/* q_sort: quick sort, non-optimal implementation */
void q_sort(int a[], int l, int r) {
	int i, last;
	void swap(int [], int, int);
	int partition(int a[], int l, int r);

	if (l >= r) {
		return;
	}

	i = partition(a, l, r);
	swap(a, i, l); // put partition element to the left

	last = l;
	for (i = l + 1; i <= r; ++i) {
		if (a[i] < a[l]) { // compare to the partition element
			swap(a, ++last, i);
		}
	}

	// put partition element back
	swap(a, l, last);

	// sort left and right parts
	q_sort(a, l, last-1);
	q_sort(a, last+1, r);
}

int partition(int a[], int l, int r) {
	return (l + r) / 2;
}

void swap(int a[], int i, int j) {
	int t;
	t = a[i];
	a[i] = a[j];
	a[j] = t;
}