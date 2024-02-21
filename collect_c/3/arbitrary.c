/*include the libraries*/
#include <stdio.h>
#include <ctype.h>

/*define the TABSIZE and the LINESIZE*/
#define TABSIZE		8
#define LINESIZE	80

/*main part of the program*/
int main()
{
	int	column, c;

	column = 0;

	while((c = getchar()) != EOF)
	{
		if(c == '\t')
			column += TABSIZE;
		else if(c == '\n')
			column = 0;
		else
			column++;

		/*long lines are broken and non-graphic characters are printed
		 *in hexadecimal
		 */

		if(isprint(c) || c == '\t' || c == '\n')
		{
			if(column > LINESIZE)
			{
				putchar('\n');
				column = c == '\t' ? TABSIZE : 1;
			}
			putchar(c);
		}
		else
		{
			if((column += 3) > LINESIZE)
			{
				putchar('\n');
				column = 4;
			}
			/*print the output*/
			printf("\\x%.2x", c);
		}
	}
	return 0;
}