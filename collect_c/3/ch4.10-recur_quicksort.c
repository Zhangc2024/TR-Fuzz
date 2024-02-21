#include <stdio.h>

void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);
	void listarr(int a[], int n);
	
	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for(i = left+1; i <= right; i++)
		if (v[i] < v [left])
			swap(v, ++last, i);
	swap(v, left, last);
	listarr(v, 8);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(int v[], int i, int j)
{
	int temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void listarr(int a[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf ("%d ", a[i]);
    }
    printf ("\n");
}

main(){
	int v[] = {1,7,3,5,6,2,4,8};
	listarr(v, 8);
	qsort(v, 0, 7);
	listarr(v, 8);
}
