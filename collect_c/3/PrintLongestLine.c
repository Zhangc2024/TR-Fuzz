/* Example in section 1.9 */ 

/* This program defines a getline function, which
   conflicts with the stdio getline. 
   However, it can be compiled correctly with 
   clang PrintLongestLine.c -std = c89

   It seems the getline function was standardized
   in 2008, 20 years after the publication of the
   K&R C book. 

   See this link for more details. 
   http://stackoverflow.com/questions/8763052/why-do-i-get-a-conflicting-types-for-getline-error-when-compiling-the-longest
*/ 

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline); 
void copy(char to[], char from[]); 

/* print longest input line */ 
int main()
{
    int len; 
    int max; 
    char line[MAXLINE]; // current line
    char longest[MAXLINE]; // longest saved line

    max = 0; 
    while ((len = getline(line, MAXLINE)) > 0)
	if (len > max) {
	    max = len; 
	    copy(longest, line); 
	}
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
