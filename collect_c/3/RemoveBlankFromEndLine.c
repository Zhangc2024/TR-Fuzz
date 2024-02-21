/* Exercise 1-18 */ 

/* A program that removes trailing blanks and tabs 
   from each line of input, and to delete entirely
   blank lines.
*/

#include <stdio.h>
#define MAXLINE  1000 /* maximum input line size */

int getline(char line[], int maxline); 
void copy(char to[], char from[]); 
int rmblank(char line[], int length); 
void setline(char line[], int length); 

/* remove blank at the end of the lines */ 
int main()
{
    int len; 
    char line[MAXLINE]; // current line
    char longest[MAXLINE]; // longest saved line

    while ((len = getline(line, MAXLINE)) > 0) {
	len = rmblank(line, len); 
	if (len > 0)
	    setline(line, len); 
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

/* rmblank: remove the blanks at the end of s[], 
   return the length of the modified string.
*/
int rmblank(char line[], int length)
{
    /* the last char must be '\n'*/
    /* hence start at the 2nd last */
    int index  = length - 2; 

    int c = line[index]; 
    
    /* loop backwards to find the first non-blank*/
    while (c == ' ' || c == '\t') {
        --index; 
	c = line[index]; 
    }

    if (index > 0) {
	line[index + 1] = '\n'; 
	line[index + 2] = '\0'; 
	return index + 2; 
    }    

    return 0; 
}

/* setline: write line[] back to standard output */
void setline(char line[], int length) 
{
    for (int i = 0; i < length; ++i) 
	putchar(line[i]);
}


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i; 
    
    i = 0; 
    while ((to[i] = from[i]) != '\0')
	++i; 
}
