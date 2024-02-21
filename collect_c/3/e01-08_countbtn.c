/*
 * Count Blanks, Tabs and New Lines
 */

#include <stdio.h>

int
main(void)
{
	int ch;
	int blanks, tabs, newlines;

	blanks = tabs = newlines = 0;
	while((ch = getchar()) != EOF)
		switch (ch) {
			case ' ':
				++blanks;
				break;
			case '\t':
				++tabs;
				break;
			case '\n':
				++newlines;
				break;
			default:
				break;
		}

	printf("Blanks\tTabs\tNewlines\n");
	printf("%d\t%d\t%d\n", blanks, tabs, newlines);

	return 0;
}
