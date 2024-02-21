#include <stdio.h>

#define TAB_SIZE 4

int main(int argc, char const *argv[])
{
	int i, c, ns;
	i = 0;
	ns = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			i = -1;
		}

		if (c == ' ') {
			++ns;
			if ((i + 1) % TAB_SIZE == 0) {
				if (ns == 1) {
					putchar(' ');
				} else {
					// adding a tab to the next tab stop
					putchar('\t');	
				}
				
				ns = 0;
			}
		} else {
			if (ns > 0) {
				for (; ns > 0; --ns) {
					// adding trailing spaces
					putchar(' ');
				}
			}
			putchar(c);
		}
		++i;
	}
	return 0;
}