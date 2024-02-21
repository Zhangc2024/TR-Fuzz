// read data from a file

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fptr;
	char c[1000];

	if ((fptr = fopen("output.out", "r")) == NULL)
	{
		printf("Error! opening the file.\n");
		exit(1);
	}

	fscanf(fptr, "%[^\n]", c);

	printf("Data from the file: \n%s", c);
	fclose(fptr);

	return 0;
}
