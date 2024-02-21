/* Exercise 1-10 */

#include <stdio.h>

/* A program that copies its input to its output. 
   replacing each table by \t, each backspace by \b 
   and each backslash by \\ . 
*/

int main()
{
    int c; 

    while ((c = getchar()) != EOF) {
	if (c == '\t') {
	    putchar('\\');
	    putchar('t');
	} else if (c == '\b') {
	    putchar('\\'); 
	    putchar('b');
	} else if (c == '\\') {
	    putchar('\\'); 
	    putchar('\\'); 
	} else {
	    putchar(c); 
	}
    }
}
