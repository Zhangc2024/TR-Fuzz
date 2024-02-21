#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

void miniprintf(char *fmt, ...);

main()
{
	miniprintf("digit:%d float:%f", 111, 111.1);
}

void miniprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;
	
	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}
