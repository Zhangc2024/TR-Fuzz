/*PLOVER: BUFF.OVER, BUFF.LENCALC*/

/*
Description: snprintf with incorrect bounds allows a stack buffer to be overrun.
Keywords: Size0 Complex1 BufferOverflow Stack Sprintf BadBound
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

	/* this is a failed attempt at fixing the bug 
	 * %35s does not limit the output length to 35
	 */
	snprintf(buf, 1024, "<%35s>", str);	/* BAD */
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

