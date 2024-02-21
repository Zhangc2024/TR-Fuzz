# include <stdio.h>

/* copy input to output */

int main(){
  int c;

  while((c = getchar()) != EOF)
    putchar(c);
}
