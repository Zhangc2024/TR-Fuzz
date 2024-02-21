/*
 * Write a program `detab` that replaces tabs in the input with the proper number
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
 * every `n` columns.
 */

#include <stdio.h>

#define MAXLINE 1000
#define SPACES_PER_TAB 4 /* As recommended by K&R */

int _getline(char line[], int maxline);

int main()
{
  int len; /* The length of the current line */
  char line[MAXLINE]; /* The current line */

  while((len = _getline(line, MAXLINE)) > 0)
    printf("%s", line);

  return 0;
}

int _getline(char line[], int lim)
{
  int c, i, j;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if (c == '\t') {
      for (j = 0; j < SPACES_PER_TAB; ++j, ++i)
        line[i] = ' ';
      --i; // Since the outer loop increments, this keeps us from losing our position.
    } else {
      line[i] = c;
    }
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }

  line[i] = '\0';
  return i;
}
