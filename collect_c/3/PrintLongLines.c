/* Exercise 1-17 */ 

/* A program that prints all input lines that are 
   are longer than 80 characters. 
*/

#include <stdio.h>
#define MAXLINE  1000 /* maximum input line size */
#define HOW_LONG 80   /* print lines longer than 
			 HOW_LONG
		      */

int getline(char line[], int maxline); 
void copy(char to[], char from[]); 

/* print longest input line */ 
int main()
{
    int len; 
    char line[MAXLINE]; // current line
    char longest[MAXLINE]; // longest saved line

    while ((len = getline(line, MAXLINE)) > 0) {
	if (len > HOW_LONG)
	    printf("%s", line); 
    }

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
