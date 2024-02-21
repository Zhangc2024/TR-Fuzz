#include <stdio.h>

int main() {
  int c, count;

  count = 0;

  while((c = getchar()) != EOF) {
    if(c != ' ' && c != '\n') {
      ++count;
    } else {
      int i;
      putchar('|');
      for(i = count; i > 0; i--) {
        putchar('=');
      }
      putchar('\n');
      count = 0;
    }
  }
  return 0;
}
