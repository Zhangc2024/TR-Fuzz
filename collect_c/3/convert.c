/*include the libraries*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*main function*/
int main(int argc, char *argv[])
{
	int	c;

	while((c = getchar()) != EOF)

		/*Depending of the System, argv[0] may contain the full
		 *calling path ot the program. The simplest solution is to 
		 *use strstr() to search for the name.
		 */
		 putchar(strstr(argv[0], "lower") != NULL
		 	? tolower(c)
			: toupper(c));

	return 0;
}