#include <stdio.h>

//run this prog by itself
int main()
{
	int c;
	
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			putchar(' ');
			while ((c = getchar()) != EOF && == ' ')
			
					;
		}
		if (c != EOF)
		
		putchar(c);
	}
}
