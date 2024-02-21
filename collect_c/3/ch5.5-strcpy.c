#include <stdio.h>

/*
stcpy: copy t to s;

void strcpy(char *s, char *t)
{
	int i;
	
	i = 0;
	while ( (s[i] = t[i]) != '\0' )
		i++;
}

void strcpy(char *s, char *t)
{
	while ((*s = *t) != '\0'){
		s++;
		t++;
	}
}

void strcpy(char *s, char *t)
{
	while ((*s++ = *t++) != '\0')
		;
}
*/

void strcpyx(char *s, char *t)
{
	while (*s++ = *t++)
		;
}

main(){
	char t[] = "hello, world";
	char s[12];
	
	strcpyx(s, t);
	
	printf("t: %s \n", t);
	printf("s: %s", s);
}
