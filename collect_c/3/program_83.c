// print all the strings in dictionary order

#include <stdio.h>
#include <string.h>

int main()
{
	int i, j;
	char str[5][50], temp[50];

	printf("Please enter 5 words:\n");

	for (i = 0; i < 5; i++)
	{
		scanf("%s", str[i]);
	}

	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (strcmp(str[i], str[j]) > 0)
			{
				strcpy(temp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], temp);
			}
		}
	}

	printf("Sorted list of words:\n");
	for (i = 0; i < 5; i++)
	{
		printf("%s\n", str[i]);
	}

	return 0;
}
