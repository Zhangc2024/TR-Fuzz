/*PLOVER: BUFF.OVER*/

/*
Description: sprintf allows a stack buffer to be overrun.
Keywords: Size0 Complex0 BufferOverflow Stack Sprintf Unbounded
ValidArg: "a"*30
InvalidArg: "a"*100
*/

#include <stdio.h>
#include <string.h>

#define	MAXSIZE		40
void
test(char *str)
{
	char buf[MAXSIZE];

	sprintf(buf, "<%s>", str);		/* BAD */
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

