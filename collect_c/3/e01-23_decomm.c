/*
 * Removes all comments from a C program.
 */

#include <stdio.h>

enum char_state {
	CODE,		/* Outside a comment. Print everything to stdout. */
	LEADIN,		/* On the first char entering the comment, i.e., /. */
	COMMENT,	/* Inside a comment. Delete everything. */
	LEADOUT		/* On the first char exiting the comment, i.e., *. */
};

/*
 * Removes all comments from a C program.
 * C comments do not nest.
 * Doesn't yet handle double quoted strings.
 * Doesn't yet handle "This is a quote character: \"."
 * Doesn't delete leading or trailing whitespace around the comment.
 */
int
main(void)
{
	int ch;

	enum char_state state = CODE;	/* Start off printing everything. */
	while ((ch = getchar()) != EOF) {
		switch (state) {
		case CODE:
			if (ch == '/')
				state = LEADIN;
			else
				putchar(ch);
			break;
		case LEADIN:
			if (ch == '*')
				state = COMMENT;
			else {
				putchar('/');
				putchar(ch);
				state = CODE;
			}
			break;
		case COMMENT:
			if (ch == '*')
				state = LEADOUT;
			break;
		case LEADOUT:
			if (ch == '/')
				state = CODE;
			break;
		default:
			break;
		}
	}
	return (0);
}
