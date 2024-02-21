/*
 * Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int _getline(char line[], int maxline);
void reverse(char s[], int len);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = _getline(line, MAXLINE)) > 0) {
    reverse(line, len);
    printf("%s", line);
  }

  return 0;
}

int _getline(char s[], int lim) {

  int c, i;

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

void reverse(char s[], int len) {
  int i, t;

  for (i = 0; i < len / 2; ++i) {
    t = s[i];
    s[i] = s[len-2-i];
    s[len-2-i] = t;
  }
}
