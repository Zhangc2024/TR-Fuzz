/*PLOVER: BUFF.OVER */

/*
Description: An ad-hoc string copy without bounds check overflows a stack buffer.
Keywords: Size0 Complex0 BufferOverflow Stack AdHocCopy Unbounded
ValidArg: "a"*30
InvalidArg: "a"*100
*/

#include <stdio.h>
#include <string.h>

#define	MAXSIZE		40
void
test(char *str)
{
	char buf[MAXSIZE], *p;

	p = buf;
	while((*p++ = *str++))				/* BAD */
		continue;
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
