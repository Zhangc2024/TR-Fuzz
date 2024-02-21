#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <stdarg.h>

/*	Ex 7-3	*/

void minprintf(char *fmt, ...) {
	va_list ap;
	char *p, *sval;
	char curfmt[BUFSIZ];
	int i, ival;
	unsigned uval;
	double dval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}

		i = 0;
		for (curfmt[i++] = '%'; i < BUFSIZ - 1 && !isalpha(curfmt[i++] = *++p);)
			;
		curfmt[i] = '\0';

		switch (*p) {
		case 'i':
		case 'd':
			ival = va_arg(ap, int);
			printf(curfmt, ival);
			break;
		case 'x':
		case 'X':
		case 'u':
		case 'o':
			uval = va_arg(ap, unsigned);
			printf(curfmt, uval);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf(curfmt, dval);
			break;
		case 's':
			sval = va_arg(ap, char*);
			printf(curfmt, sval);
			break;
		default:
			printf(curfmt);
			break;
		}

	}

	va_end(ap);
}

int main() {
	minprintf("%d", 10);
}
