#include <stdio.h>

int binarysearch(int x, int v[], int n)
{
	int		low, high, mid;
	
	low = 0;
	high = n - 1;
	while (low < high)
	{
		mid = (low + high) / 2;
		if(x > v[mid])
			low = mid + 1;
		else
			high = mid;
	}
	
	if(v[low] == x)
		return low;
	else
		return - 1;
}

#define N		11

int V[N] = { 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 31 };

int main()
{
	printf("%d\n", binarysearch(7, V, N));
	printf("%d\n", binarysearch(8, V, N));
	return 0;
}
