#include <stdio.h>
#define MAXLINE 1000
#define MORETHAN 80

int getlinf(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
	int len;                     /* current line length */
	int max;					 /* maxlength seen so far */
	char line[MAXLINE];			 /* current input line */
	char longest[MAXLINE];		 /* longest line saved here */

	max = 0;
	while ( (len = getlinf(line, MAXLINE)) > 0 ){
		if ( len > MORETHAN ) {
			printf("current line length more than %4d\n", MORETHAN);
			printf("%s", line);
			printf("---\n");
		}
	}
	return 0;
}

/* getline: read a line into s, return length */
int getlinf(char s[], int lim)
{
	int c, i;

	for  (i=0; (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n'){
        s[i] = c;
        ++i;
    	s[i] = '\0';
	}
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i=0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
