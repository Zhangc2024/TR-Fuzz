/*PLOVER: RES.MEMLEAK*/

/*
Description: malloc'd data is never freed and all pointers to the data are lost.
Keywords: Size0 Complex0 Api MemMgmt Leak
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
test(char *str)
{
	char *p;

	p = strdup(str);
	if(p)
		printf("result: %s\n", p);

	/* there's no free and p is a local variable */
	return;					/* BAD */
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

