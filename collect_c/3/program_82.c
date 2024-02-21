// perform copy operation over string without using strcpy()

#include <stdio.h>

int main()
{
	int i;
	char str1[100], str2[100];

	printf("Please enter string: ");
	scanf("%s", str1);

	for (i = 0; str1[i] != '\0'; i++)
	{
		str2[i] = str1[i];
	}
	str2[i] = '\0';

	printf("Second string: %s.\n", str2);

	return 0;
}
