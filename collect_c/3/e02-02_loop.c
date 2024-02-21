/*
 * Write an equivalent loop without using && or ||.
 */

#include <stdio.h>

/*
 * Write an equivalent loop without using && or ||.
 */
int
main(void)
{
	int	lim = 1000;
	char	s[lim];
	int	c, i, j;

	/* Original loop with &&. */
	for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;
	s[i] = '\0';

	for (j = 0; s[j] != '\0'; j++)
		putchar(s[j]);

	printf("\n");

	/* Revised loop without && or ||. */
	for (i = 0; i < lim - 1; ++i) {
		c = getchar();
		if (c == '\n')
			break;
		else if (c == EOF)
			break;
		else
			s[i] = c;
	}
	s[i] = '\0';

	for (j = 0; s[j] != '\0'; j++)
		putchar(s[j]);

	printf("\n");

	return (0);
}
