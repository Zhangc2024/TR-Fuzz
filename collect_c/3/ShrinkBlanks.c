/* Exercise 1-9 */

#include <stdio.h>

#define CHAR_SEQUENCE  0
#define SPACE_SEQUENCE 1

/* A program that copies its input to its output
   replacing each string of one or more blanks by a single blank. 
 */

int main()
{
    int c; 
    int state; 

    state = CHAR_SEQUENCE; 

    while ((c = getchar()) != EOF) {
	if (state == CHAR_SEQUENCE) {
	    if (c == ' ') {
		state = SPACE_SEQUENCE; 
	    }
	    putchar(c); 
	} else {
	    if (c != ' ') {
		state = CHAR_SEQUENCE; 
		putchar(c); 
	    }
	}
    }
}
