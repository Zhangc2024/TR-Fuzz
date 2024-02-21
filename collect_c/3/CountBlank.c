/* Exercise 1-8 */

#include <stdio.h>

/* A program that counts blanks, tabs and newlines. */
int main()
{
    int c; 
    int nb, nt, nl; /* number of blanks, tabs and new lines*/

    nb = nt = nl = 0; 
    while ((c = getchar()) != EOF) {
	if (c == ' ')
	    ++nb; 
	if (c == '\t')
	    ++nt; 
	if (c == '\n')
	    ++nl; 
    }
    printf("Blanks:%d\tTabs:%d\tLines:%d\n", nb, nt, nl); 
}
