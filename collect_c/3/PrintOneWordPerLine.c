/* Exercise 1-12 */

#include <stdio.h>

#define IN          1
#define OUT         0

/* A program that printes its input one word per line */

int main()
{
    int c, state; 
    
    state = OUT; 
    while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    if (state == IN) {
		putchar('\n'); 
	    }
	    state = OUT; 
	} else {
	    if (state == OUT) {
		state = IN; 
	    }
	    putchar(c);
	}
    }
}
