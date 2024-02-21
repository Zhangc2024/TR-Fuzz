#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int binsearch1(int x, int v[], int n) {
	int lo, mid, hi;
	lo = 0;
	hi = n - 1;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (x < v[mid])
			hi = mid - 1;
		else if (x > v[mid])
			lo = mid + 1;
		else
			return mid;
	}

	return -1;
}

int binsearch2(int x, int v[], int n) {
	int lo, mid, hi;
	lo = 0;
	hi = n - 1;
	mid = (lo + hi) / 2;
	while (lo <= hi && x != v[mid = (lo + hi) / 2]) {
		if (x < v[mid])
			hi = mid - 1;
		else
			lo = mid + 1;
	}

	if (lo > hi)
		return -1;
	else
		return mid;
}


