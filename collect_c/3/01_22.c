/*
 * Write a program to `fold` long input lines into two or more shorter
 * lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent
 * with very long lines, and if there are no blanks or tabs before the
 * or tabs before the specified column.
 */

#include <stdio.h>

#define MAXLINE 1000
#define FOLD 20 /* essentially a word wrap marker... .but this is what K&R calls it so... */

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
  int c, i, j;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {

    // fold the lines
    if (i > 0 && i % FOLD == 0) {
      // Prevents breaking on words by iterating backwards
      // and replacing the final blank or tab with a newline.
      if (s[i-1] != ' ' || s[i-1] != '\t') {
        for (j = i-1; s[j] != ' ' || s[j] != '\t'; j--)
          ;
        s[j] = '\n';
      } else {
        s[i] = '\n';
        ++i;
      }
    }

    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}
