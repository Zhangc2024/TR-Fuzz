#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100
#define NUMBER '0'

int getline(char line[], int limit);
int li = 0;
char line[MAXLINE];

/* getop: get next operator or numberic operand */
int getop(char s[])
{
	int c, i;
	
	if (line[li] == '\0')
		if (getline(line, MAXLINE) == 0)
			return EOF;
		else
			li = 0;
	while ((s[0] = c = line[li++]) == ' ' || c == '\t')
		;
	s[1] - '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = line[li++]))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = line[li++]))
			;
	s[i] = '\0';
	li--;
	return NUMBER;
			
}

/*
gcc 4.3\calc.c 4.3\pushpop.c 04-10.c 4.2\getline.c 
*/
