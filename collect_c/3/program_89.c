// write a sentance to a file

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char sentence[100];

	FILE *fptr;

	fptr = fopen("output.out", "w");

	if (fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}

	printf("Please enter the sentence: ");
	// scanf("%s", sentence);
	fgets(sentence, sizeof(sentence), stdin);

	fprintf(fptr, "%s", sentence);
	fclose(fptr);

	return 0;
}
