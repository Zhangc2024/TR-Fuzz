/*PLOVER: BUFF.OVER*/

/*
Description: An strcpy overflows a stack buffer.  A check was made to avoid an overflow condition but the check is off by one.
Keywords: Size0 Complex0 BufferOverflow Stack Strcpy Unbounded
ValidArg: "a"*30
InvalidArg: "a"*100

Due to the nature of this bug, the Invalid test case may overflow padding
or other unimportant data and not crash.
*/

#include <stdio.h>
#include <string.h>

#define	MAXSIZE		5
void
test(char *str)
{
	char buf[MAXSIZE];

	if(strlen(str) > MAXSIZE)
		return;
	strcpy(buf, str);				/* BAD */
	printf("result: %s\n", buf);
}

int
main(int argc, char **argv)
{
	char *userstr;

	if(argc > 1) {
		userstr = argv[1];
		test(userstr);
	}
	return 0;
}

