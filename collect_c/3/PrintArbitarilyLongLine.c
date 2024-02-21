/* Exercise 1-16  
   Modified from example in section 1.9
   Compile with 
   clang PrintArbitarilyLongLine.c -std=c89
*/ 

/* This exercise requires priting the length of the long
   input line, which may have arbitrary length. It also 
   asks for 'as much as possible' of the text. 

   If no dynamic memory allocation is allowed, the longest
   string this program can store for one line has length
   MAXLINE. In another word, only the last MAXLINE number
   of characters will be printed. 

   All these said, it is easier to only store the tail of 
   the line after a multiple of MAXLINEs are read in. 
*/

#include <stdio.h>
#define MAXLINE 10 /* maximum input line size */
                   /* set to a small const for testing */

#define IN   1     /* still in the current line */
#define OUT  0     /* different line */

int getline(char line[], int maxline); 
void copy(char to[], char from[]); 

/* print longest input line */ 
int main()
{
    int len;            // length returned from getline, always < MAXLINE
    int currlen;        // actual length of the string
    int state; 
    int max; 
    char line[MAXLINE]; // current line
    char longest[MAXLINE]; // longest saved line

    max = 0; 
    currlen = 0; 
    state = OUT; 
    while ((len = getline(line, MAXLINE)) > 0) {
	if (len == MAXLINE - 1 && line[len - 1] != '\n') {
	    state = IN; 
	    currlen = currlen + len; 
	} else {
	    if (state == IN)
		currlen = currlen + len; 
	    else
		currlen = len; 
	    state = OUT; 
	}
	
	if (currlen > max) {
	    max = currlen; 
	    copy(longest, line); 
	}
	
	if (state == OUT)
	    currlen = 0; 
    }
    
    printf("Max length is: %d\n", max); 
    if (max > 0) /* there was a line */
	printf("%s", longest); 

    return 0; 
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i; 
    
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
	s[i] = c; 
    if (c == '\n') {
	s[i] = c; 
	++i; 
    }
    s[i] = '\0';
    return i; 
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i; 
    
    i = 0; 
    while ((to[i] = from[i]) != '\0')
	++i; 
}
