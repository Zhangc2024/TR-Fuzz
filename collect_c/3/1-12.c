#include <stdio.h>

/* Print each word of input on a new line */
int main()
{
	int c;

	while ((c = getchar()) != EOF) {
    if(c == ' ') {
      putchar('\n');
    } else {
      putchar(c);
    }
	}

  return 0;
}
