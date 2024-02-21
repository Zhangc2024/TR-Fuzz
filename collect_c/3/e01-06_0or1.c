/*
 * Verify that `getchar() != EOF' is 0 or 1.
 */

#include <stdio.h>

int
main(void)
{
	int c;

	c = getchar() != EOF;
	printf("%d\n", c);

	return 0;
}
