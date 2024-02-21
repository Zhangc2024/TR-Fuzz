/*
 * Write a program to remove trailing blanks and tabs from
 * each line of input, and to delete entirely blank lines.

 NOTE: Not entirely sure what 'delete entirely blank line'
   is requesting as we can technically view an entirely
   blank line as simply one long trailing whitespace.
 **/

#include <stdio.h>

#define MAXSIZE 1000 // Number of characters in character array 

int _getline(char line[], int maxsize);

int main()
{
  int len; // The length of the line
  char line[MAXSIZE]; // The line of text

  while ((len = _getline(line, MAXSIZE)) > 0) {
    if (len > 0)
      printf("%s", line);
  }

  return 0;
}

int _getline(char s[], int lim)
{
  int i, c;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  // Remove trailing blanks and tabs
  while (s[i-1] == ' ' || s[i-1] == '\t')
    --i;

  if (c == '\n') {
    s[i] = '\n';
    ++i;
  }

  s[i] = '\0';

  return i;
}
