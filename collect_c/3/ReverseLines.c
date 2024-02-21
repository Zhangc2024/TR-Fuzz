/* Exercise 1-19 */ 

/* A function reverse(s) that reverses the 
   character string s and a program that reverses 
   its input a line at a time. 
*/

/* It is not specified in the exercise how to deal 
   with trailing blanks when reversing the line. 
   This program does not remove the trailing blanks. 
   It can be combined with RemoveBlankFromEndLine.c
   to remove the trailing blanks and then perform
   the reversion. 
*/

#include <stdio.h>
#define MAXLINE  1000 /* maximum input line size */

int getline(char line[], int maxline); 
void copy(char to[], char from[]); 
void setline(char line[]); 

void reverse(char s[]);

/* reverse input one line a time */
int main()
{
    int len; 
    char line[MAXLINE]; // current line
    char longest[MAXLINE]; // longest saved line

    while ((len = getline(line, MAXLINE)) > 0) {
	reverse(line); 
	if (len > 0)
	    setline(line); 
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


/* setline: write line[] back to standard output */
void setline(char line[]) 
{
    int i = 0; 
    while (line[i] != '\0') {
	putchar(line[i]); 
	++i; 
    }
}


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i; 
    
    i = 0; 
    while ((to[i] = from[i]) != '\0')
	++i; 
}

/* reverse: reverse char string s 
   assumes that s is a line and always end with
   \n\0. 
*/
void reverse(char s[])
{
    int len, c; 

    /* first loop to find the length */
    len = 0; 
    c = s[len];
    while (c != '\0') {
	++len; 
	c = s[len]; 
    }

    /* then swap the chars in place to reverse */ 
    for (int i = 0; i <= (len - 2) / 2; ++i) {
	int t = s[i]; 
	s[i] = s[len - 2 - i]; 
	s[len - 2 - i] = t; 
    }
}
