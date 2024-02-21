#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <stdarg.h>

#define NUMBER 0
#define MATHFUNC 1

/*	Ex 7-5	*/
int getop(char *s) {
	int c, type;
	float fval;

	if (scanf(" %c", &c) == EOF)
		return EOF;

	/*	match token pattern	*/
	type = c;
	if (islower(c)) {
		ungetc(c, stdin);
		scanf("%s", s);
		if (strlen(s) == 3)
			type = MATHFUNC;
	}

	else if (c == '-' && !isdigit(ungetc(getchar(), stdin)))
		*s = type = c;

	else if (c == '-' || isdigit(c)) {
		ungetc(c, stdin);
		scanf("%f", &fval);
		sprintf(s, "%f", fval);
		type = NUMBER;
	}

	return type;
}
int main(){

}
