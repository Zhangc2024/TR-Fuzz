#include "stdio.h"
#include "unistd.h"

int getchar2();

main ()
{
	int c;
	c = getchar2();
	putchar(c);
}

int getchar2()
{
	char c;

	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}
