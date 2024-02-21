/*
 * Write a program `entab` that replaces strings of blanks by the minimum
 * number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for `detab`. When either a tab or a single blank would
 * suffice to reach a tab stop, which should be given preference?
 */

#include <stdio.h>

#define MAXLINE 1000
#define SPACES_PER_TAB 4

int _getline(char line[], int maxline);

int main()
{
  char line[MAXLINE];

  while (_getline(line, MAXLINE) > 0)
    printf("%s", line);

  return 0;
}

int _getline(char s[], int lim)
{
  int c, i, bc;
 
  bc = 0; /* initialize blank-space counter */
  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if (c == ' ') {
      ++bc;
      if (bc == SPACES_PER_TAB) {
        i -= (bc-1);
        c = 'X';
        bc = 0; /* reset the counter */
      }
    } else {
      bc = 0; /* reset the counter */
    }

    s[i] = c;
  }

  if (c == '\n') {
    s[i] = '\n';
    ++i;
  }

  s[i] = '\0';
  return i;
}

