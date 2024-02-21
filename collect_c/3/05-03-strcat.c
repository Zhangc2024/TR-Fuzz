#include <stdio.h>

/* strcat: concatenate t to the end of s; pointer version */
void strcatx(char *s, char *t)
{
	while (*s)
		s++;
	while (*s++ = *t++)
		;
}

main()
{
	char s[]="hello";
	char t[]=" world";
	strcatx(s,t);
	printf("%s", s);
}
