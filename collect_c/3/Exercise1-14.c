#include <stdio.h>

int main () {
	int counter[91];
	int c, i, j;
	
	for (i = 65; i < 91; i++)
		counter[i] = 0;
		
	while ((c = getchar()) != EOF)
		++counter[c-32];
	
	printf("\nLETTERS HISTOGRAM\n\n");
	for (i = 65; i < 91; i++)
	{
		putchar(i+32);
		printf("  ");
		for (j = 0; j < counter[i]; j++)
			printf("*");
		printf("\n");
	}
	
}
