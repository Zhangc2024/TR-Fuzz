/* Program to remove legacy C comments 
 * From a C program
 */
#include <stdio.h>
#include <stdlib.h>

void rm_comment(int c);
void in_comment(void);
void print_quote(int c);

/* remove all comments from a valid C program */
int main() 
{
  int c, next_c;

  while ((c = getchar()) != EOF) {
    rm_comment(c);
  }
  return 0;
  
}

void rm_comment(int c)
{

  int next_c;

  if (c == '/')
    if ((next_c = getchar()) == '*') {
      in_comment();
    } else if (next_c == '/') {
      putchar(c);
      rm_comment(next_c);
    } else {
      putchar(c);
      putchar(next_c);
    }
  else if (c == '\'' || c == '"') {
    print_quote(c);
  } else {
    putchar(c);
  }
}

/* in_comment: inside of a valid comment     */
void in_comment(void)
{
  int c, next_c;

  c = getchar();
  next_c = getchar();
  while (c != '*' || next_c != '/') {
    c = next_c;
    next_c = getchar();
  }
}

/* print_quote: print characters within quotes */
void print_quote(int c)
{

  int next_c;

  putchar(c);
  while ((next_c = getchar()) != c) {
    putchar(next_c);
    if (next_c == '\\')
      putchar(getchar());
  }
  putchar(next_c);
}

  
  

