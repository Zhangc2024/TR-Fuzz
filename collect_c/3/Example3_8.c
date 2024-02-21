#include<stdio.h>

main () {
	
	int i, n = 12;
	int a[12] = {-1, 7, -9, 25, -38, 46, -56, 64, -74, 81, -99, 100};
	
	printf("These numbers are positive: ");
	for (i = 0; i < n; i++) {
		if (a[i] < 0) /* skip negative elements */
			continue;
		printf("%i ", a[i]); /* do positive elements */ 	
	} 
	
	printf("\n\nThese numbers are negative: ");
	for (i = 0; i < n; i++) {
		if (a[i] > 0) /* skip positive elements */
			continue;
		printf("%i ", a[i]); /* do negative elements */ 	
	} 
	printf("\n");
}



