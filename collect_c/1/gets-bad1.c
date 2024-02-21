/*PLOVER: BUFF.OVER*/

/*
Description: gets is never safe for untrusted input due to lack of buffer length checks.
Keywords: Size0 Complex0 BufferOverflow Stack Gets Unbounded
ValidStream: "a"*30
InvalidStream: "a"*200
*/

#include <stdio.h>
#include <string.h>

#define	MAXSIZE		40
void
test(void)
{
	char buf[MAXSIZE];

	if(gets(buf))					/* BAD */
		printf("result: %s\n", buf);
}

int
main(int argc, char **argv)
{
	test();
	return 0;
}

