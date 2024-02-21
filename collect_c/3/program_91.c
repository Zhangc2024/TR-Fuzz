// read the data from the current file

#include <stdio.h>

int main()
{
	FILE *fptr;
	int c;

	fptr = fopen(__FILE__, "r");

	do {
		c = getc(fptr);
		putchar(c);
	}
	while (c != EOF);

	fclose(fptr);
	return 0;
}
