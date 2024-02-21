// find the frequency of a character in a string

#include <stdio.h>

int main()
{
	char str[100], ch;
	int i, count = 0;

	printf("Please enter a string: ");
	fgets(str, sizeof(str), stdin);

	printf("Enter the character to be counted: ");
	scanf("%c", &ch);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (ch == str[i])
		{
			count++;
		}
	}

	printf("Frequency of %c is %d.\n", ch, count);

	return 0;
}
