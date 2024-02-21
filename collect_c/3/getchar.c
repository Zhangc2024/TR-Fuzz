#include <unistd.h>
#include <stdio.h>

int getchar_sys(void);

int main(int argc, char const *argv[])
{
	int c;
	while ((c = getchar_sys()) != EOF) {
		putchar(c);
	}

	return 0;
}

int getchar_sys(void) {
	static char buf[BUFSIZ];
	static char *bufp;
	static int n;

	if (n == 0) {
		n = read(0, buf, sizeof buf);
		bufp = buf;
	}

	return (n-- > 0) ? (unsigned char) *bufp++ : EOF;
}