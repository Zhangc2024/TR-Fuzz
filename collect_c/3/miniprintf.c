#include <stdarg.h>
#include <stdio.h>

void miniprintf(char *, ...);

int main(int argc, char const *argv[])
{
	miniprintf("%s\n", "hello, world");
	miniprintf("%d\n", 100-3);
	miniprintf("%f\n", 10.0/3.0);

	return 0;
}

/* miniprintf: minimal printf with variables argument list */
void miniprintf(char *fmt, ...) {
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt); // make ap points to the first unnamed argument
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
				printf("%lf", dval);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++) {
					putchar(*sval);
				}
				break;
			default:
				putchar(*p);
				break;
		}
	}
	va_end(ap);
}
