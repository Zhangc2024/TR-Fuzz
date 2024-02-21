// print the length of string

#include <stdio.h>

int main()
{
	char str[100];
	int i;

	printf("Please enter the string: ");
	fgets(str, sizeof(str), stdin);

	for (i = 0; str[i] != '\n'; i++);

	printf("Length of %s is %d.\n", str, i);

	return 0;
}
