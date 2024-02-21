#include <stdio.h>

#define ALPHABET_SIZE 	26
#define HISTOGRAM_SIZE	40

int main()
{
	int i, counts[ALPHABET_SIZE], max, c;
	
	for (i = 0; i < ALPHABET_SIZE; i++)
	
		counts[i] = 0;
		
		
	max = 1;
	while ((c = getchar()) != EOF)
	{
		if (c >= 'a' && c <= 'z')
			c = 'A' + c - 'a';
		if (c >= 'A' && c <= 'Z')
			if (++counts[c - 'A'] > max)
				max = counts[c - 'A'];
	}
	
	for (i = 0; i < ALPHABET_SIZE; i++)
	{
		printf("%c: ", (char) 'A' + 1);
		
		c = HISTOGRAM_SIZE * counts[i] / max;
		while (c-- > 0)
			putchar('=');
			putchar('\n');
	}
}
