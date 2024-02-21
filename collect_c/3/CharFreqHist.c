/* Exercise 1-14 */

#include <stdio.h>

/* A program that prints a histogram of the frequencies
   of different characters in its input 
*/

/* This exercies does not specify what in the input count
   as characters. It is assumed here that the characters 
   concerned are the ASCII printable characters, character
   code from 32 to 126. See http://www.ascii-code.com/ for
   more details. 
*/

#define NUM_PRINTABLE_CHARS 95

void printhist(int num); 

int main()
{
    int c; 
    int charFreq[NUM_PRINTABLE_CHARS]; 

    for (int i = 0; i < NUM_PRINTABLE_CHARS; ++i)
	charFreq[i] = 0; 

    /* calculate the frequencies */
    while ((c = getchar()) != EOF) {
	// check for printable chars. 
	if (c >= ' ' && c <= '~') {
	    ++charFreq[c - ' ']; 
	}
    }

    /* print the histogram */
    for (int i = 0; i < NUM_PRINTABLE_CHARS; ++i) {
	printf("%c\t|", i + ' '); 
	printhist(charFreq[i]); 
	printf("\n"); 
    }
}

void printhist(int num)
{
    for (int i = 0; i < num; ++i)
	printf("*"); 
}
