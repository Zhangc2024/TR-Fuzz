#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getop(char s[]);

main(){
	char s[10];
	getop(s);
	printf("%s", s);
}

/* getop: get next operator or numeric operand
  codeblock 16.01 declare c as short int in. */
int getop(char s[])
{
	short int c, i, rc;
	static char lastc[] = " ";

	sscanf(lastc, "%c", &c);
	lastc[0] = ' ';
	while ((s[0] = c) == ' ' || c == '\t')
		if (scanf("%c", &c) == EOF)
			 c = EOF;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		do {
			rc = scanf("%c", &c);
			if (!isdigit(s[++i] = c))
				break;
		} while (rc != EOF);

	if (c == '.')
		do {
			rc = scanf("%c", &c);
			if (!isdigit(s[++i] = c))
				break;
		} while (rc != EOF);
	s[i] = '\0';
	if (rc != EOF)
		lastc[0] = c;
	return NUMBER;
}
