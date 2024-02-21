#include<stdio.h>
#include<windows.h>

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n) { 

	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
			
}

main() {
	
	int n = 10, i;
	int v[10];
	
	printf("Enter the amount of numbers to sort: \n");
	scanf("%i", &n);

	printf("Enter %i numbers separated with an enter please: \n", n);
	for(i = 0; i < n; i++) {
		scanf("%i", &v[i]);
	}
	
	shellsort(v, n);
	
	printf("\nThe numbers in order are: ");
	for(i = 0; i < n; i++)
		i == (n - 1) ? printf("%i ", v[i]) : printf("%i, ", v[i]);
	printf("\n");
}

