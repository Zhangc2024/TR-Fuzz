/* Exercise 1-13 */ 

#include <stdio.h>

/* A program to print a histogram of the lengths of words
   in its input. Bars are drawn horizontally. 
*/

/* The exercise does not specify the number and sizes of the 
   bins. It is assumed here that there are 10 bins and the size of 
   each is one char. 
*/

#define NUMBER_OF_BINS  10
#define MAX_LENGTH       9  /* the last bin holds words longer than
			       MAX_LENGTH
			     */

#define IN              1
#define OUT             0

void printhist(int num); 

int main()
{
    /* PART 1 - count the sizes of the words
       and store them in an array. 
    */

    int c, wordLength, state; 
    int nWordLength[NUMBER_OF_BINS]; 

    wordLength = 0; 
    for (int i = 0; i < NUMBER_OF_BINS; ++i)
	nWordLength[i] = 0; 
    
    state = OUT; 
    while ((c = getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t') {
	    if (state == IN) {
		if (wordLength > MAX_LENGTH) {
		    ++nWordLength[NUMBER_OF_BINS - 1]; 
		} else {
		    ++nWordLength[wordLength - 1]; 
		}
		wordLength = 0; 
	    }
	    state = OUT; 
	} else {
	    if (state == OUT) {
		state = IN;  
	    }
	    ++wordLength; 
	}
    }

    /* PART 2 - print the histogram */
    for (int i = 0; i < NUMBER_OF_BINS - 1; ++i) {
	printf("Length of \t%2d\t| ", i + 1); 
	printhist(nWordLength[i]); 
	printf("\n"); 
    }

    printf("Longer than \t%2d\t| ", MAX_LENGTH); 
    printhist(nWordLength[MAX_LENGTH]); 
    printf("\n"); 
         
    printf("\n"); 
}

void printhist(int num)
{
    for (int i = 0; i < num; ++i)
	printf("*");  
}
