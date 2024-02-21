/*
 * TODO
 * Write a program to remove all comments from a C program. Don't forget
 * to handle quoted strings and character constants properly. C comments
 * don't nest.
 */

#include <stdio.h>

#define MAXLINE 1000

int _getline(char line[], int maxline);

int main()
{
  char line[MAXLINE];

  while ((_getline(line, MAXLINE)) > 0)
    printf("%s", line);

  return 0;
}

int _getline(char s[], int lim)
{
  int i, c;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}
