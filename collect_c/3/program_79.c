// remove all the characters that are not alphabets in the string

#include <stdio.h>

int main()
{
	char str[100];
	int i, j, k;

	printf("Please enter a string: ");
	fgets(str, sizeof(str), stdin);

	for (i = 0; str[i] != '\0'; i++)
	{
		while (!(str[i] >= 'a' && str[i] <= 'z') && !(str[i] >= 'A' && str[i] <= 'Z') && str[i] != '\n')
		{
			for (j = i; str[j] != '\0'; j++)
			{
				str[j] = str[j + 1];
			}
			str[j] = '\0';
		}
		puts(str);
	}

	printf("Final string: ");
	puts(str);

	return 0;
}
