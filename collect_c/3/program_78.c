// find the number of vowels and consonants in a string

#include <stdio.h>

int main()
{
	char str[100];
	int i, vowels = 0, consonants = 0;

	printf("Please enter a string: ");
	fgets(str, sizeof(str), stdin);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
		{
			vowels++;
		}
		else
		{
			consonants++;
		}
	}

	printf("There are %d vowels and %d consonants in %s", vowels, consonants, str);
	return 0;
}
