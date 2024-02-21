
#include <stdio.h>

int main()
{
  int c, seen_blank;

  seen_blank = 0;
  while((c = getchar()) != EOF) {
    if(c == ' ') {
      if(!seen_blank) {
        putchar(c);
        seen_blank = 1;
      }
    } else {
      putchar(c);
      seen_blank = 0;
    }
  }

}
