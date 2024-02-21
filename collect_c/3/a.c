#include <stdio.h>

main(int argc, char *argv[])
{
	++argv;
	putchar (argv[0][1]);
	putchar (*++argv[0]);
}
