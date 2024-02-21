# include <stdio.h>
# include <limits.h>

int main()
{
  int last, c;

  last = INT_MIN;
  while((c = getchar()) != EOF)
    if (c == ' ' && last == ' ')
      continue;
    else {
      putchar(c);
      last = c;
    }
}
