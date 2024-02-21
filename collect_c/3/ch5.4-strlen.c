#include <stdio.h>

int strlenx(char *s)
{
	char *p = s;
	
	while (*p != '\0')
		p++;
	return p - s;
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
