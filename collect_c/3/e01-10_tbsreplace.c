/*
 * Tab, Backspace, and Backslash Replace
 */

#include <stdio.h>

int
main(void)
{
	int ch;

	while ((ch = getchar()) != EOF)
		switch (ch) {
			case '\t':
				printf("\\t");
				break;
			case '\b':
				printf("\\b");
				break;
			case '\\':
				printf("\\\\");
				break;
			default:
				putchar(ch);
				break;
		}

	return 0;
}
