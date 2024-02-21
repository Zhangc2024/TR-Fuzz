/* 
 * Example 1-10.c
 *
 *
 */

#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];


int mygetline(void);
void gitqcopy(void);

/* print longest input line; external variables version */
int main()
{

  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = mygetline()) > 0)
    if (len > max) {
      max = len;
      copy();
    }

  if (max > 0) /* There was a line */
    printf("%s", longest);

  return 0;
  
}

int mygetline(void)
{

  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE -1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';
  return i;
}


/* copy: external variables version */
void copy(void)
{

  int i = 0;
  extern char line[], longest[];

  while ((longest[i] = line[i]) != '\0')
    ++i;
  
}
