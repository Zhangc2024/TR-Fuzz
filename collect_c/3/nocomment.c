/*
 * K&R Exercise 1-23
 * Write a program to remove all comments from a C program. Don't forget
 * to handle quoted strings and character constants properly. C comments
 * do not nest.
 */

#include <stdio.h>

enum bool { FALSE, TRUE };

int main(void)
{
	int c;
	int charconst;
	int string;
	int comment;

	comment = string = charconst = FALSE;
	while ((c = getchar()) != EOF) {

		// char constants only exist outside comments and strings
		if (c == '\'' && string == FALSE && comment == FALSE) {
			if (charconst == FALSE) {
				charconst = TRUE;
			} else if (charconst == TRUE) {
				charconst = FALSE;
			}
		}

		// strings only exist outside comments and char constants
		if (c == '\"' && charconst == FALSE && comment == FALSE) {
			if (string == FALSE) {
				string = TRUE;
			} else if (string == TRUE) {
				string = FALSE;
			}
		}

		// only putchar() if c is outside a comment
		if (charconst == TRUE) {
			putchar(c);
		} else if (string == TRUE) {
			putchar(c);
		} else {
			if (c == '/' && comment == FALSE) {
				if ((c = getchar()) == '*') {
					comment = TRUE;
				} else {
					putchar('/');
					putchar(c);
				}
			} else if (c == '*' && comment == TRUE) {
				if ((c = getchar()) == '/') {
					comment = FALSE;
				}
			} else if (comment == TRUE) {
				;
			} else {
				putchar(c);
			}
		}
	}
	return 0;
}
