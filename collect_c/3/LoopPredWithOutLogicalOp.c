/* Exercise 2-2 */ 

/* 
   The getline function is revised so that no && or ||
   are used. 
   The question was not specific on any other limitations. 
   So I picked the easist thing I can think of. 
*/ 

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int getline(char line[], int maxline);  

/* print all the lines to test getline */ 
int main()
{
    int len; 
    char line[MAXLINE]; /* current line */

    while ((len = getline(line, MAXLINE)) > 0)
        printf("%s", line); 

    return 0; 
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i; 
    
    i = 0; 
    while (i < lim - 1) {
	if ((c = getchar()) == EOF)
	    break; 
	if (c == '\n')
	    break; 
	s[i++] = c; 
    }

    if (c == '\n') 
	s[i++] = c;  

    s[i] = '\0';
    return i; 
}

