/*
 * Word Count
 */

#include <stdio.h>

#define	IN	1
#define	OUT	0

int
main(void)
{
	int ch, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;

	while ((ch = getchar()) != EOF) {
		++nc;
		if (ch == '\n')
			++nl;
		if (ch == ' ' || ch == '\n' || ch == '\t')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	
	printf("%d %d %d\n", nl, nw, nc);

	return 0;
}
