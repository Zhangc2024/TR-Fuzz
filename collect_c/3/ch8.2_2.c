#include "stdio.h"
#include "unistd.h"

int getchar2(void)
{
	static char buf[BUFSIZ];
	static char *bufp = buf;
	static int n = 0;

	if (n == 0) {
		n = read(0, buf, sizeof buf);
		bufp = buf;
	}

	return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

main()
{
	int c;

	c = getchar2();
	putchar(c);
}
