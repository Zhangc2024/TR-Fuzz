// concatenate two strings using loop

#include <stdio.h>

int main()
{
	int i, j;
	char str1[100], str2[100];

	printf("Please enter the first string: ");
	scanf("%s", str1);

	printf("Please enter the second string: ");
	scanf("%s", str2);

	for (i = 0; str1[i] != '\0'; i++);

	for (j = 0; str2[j] != '\0'; j++)
	{
		str1[i++] = str2[j];
	}
	str1[i] = '\0';

	printf("%s\n", str1);

	return 0;
}
