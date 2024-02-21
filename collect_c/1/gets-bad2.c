/*PLOVER: BUFF.OVER*/

/*
Description: fgets is called with an incorrect bounds allow a stack buffer to be overrun.
Keywords: Size0 Complex0 BufferOverflow Stack Gets BadBound
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

	if(fgets(buf, 1024, stdin))			/* BAD */
		printf("result: %s\n", buf);
}

int
main(int argc, char **argv)
{
	test();
	return 0;
}

