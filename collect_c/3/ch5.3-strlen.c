#include <stdio.h>

int strlenx(char *s)
{
	int n;
	
	for (n = 0; *s != '\0'; s++)
		n++;
	return n;
}


main()
{
	char array[]="hello, world"; 
	char *p;
	p = &array[0];
	
	printf("%d\n", strlenx("hello, world"));
	printf("%d\n", strlenx(array));
	printf("%d\n", strlenx(p));
}
