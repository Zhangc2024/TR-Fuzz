// print reverse of a sentence using recursion

#include <stdio.h>

void reverseSentence()
{
	char c;

	scanf("%c", &c);

	if (c != '\n')
	{
		reverseSentence();
		printf("%c", c);
	}
}

int main()
{
	printf("Please enter a sentence to reverse: ");

	reverseSentence();

	printf("\n");

	return 0;
}
