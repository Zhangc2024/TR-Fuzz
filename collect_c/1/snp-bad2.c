/*PLOVER: BUFF.OVER, BUF.LENCALC*/

/*
Description: snprintf with incorrect bounds allows a stack buffer to be overrun.
Keywords: Size0 Complex0 BufferOverflow Stack Sprintf BadBound
InvalidArg: ""
*/

#include <stdio.h>
#include <string.h>

#define	MAXSIZE		40
void
test(char *str)
{
	char buf[MAXSIZE];

	snprintf(buf, 1024, "<%s>", str);	/* OK */
	printf("result: %s\n", buf);
}

int
main(int argc, char **argv)
{
	/* overly long constant string */
	test("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	return 0;
}

