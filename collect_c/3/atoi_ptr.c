#include <stdio.h>
#include <ctype.h>

#define MAXBUF 20

int atoi_ptr(char *);

int main(int argc, char const *argv[])
{
	int c;
	char buf[MAXBUF+1];
	char *p = buf;

	while ((c = getchar()) != EOF && (p-buf) < MAXBUF) {
		*p++ = c;
	}
	*p = '\0';

	printf("%d\n", atoi_ptr(buf));

	return 0;
}

int atoi_ptr(char *s) {
	int val, sign;

	for (; *s && isspace(*s); s++)
		;

	sign = 1;
	if (*s == '-' || *s == '+') {
		if (*s == '-') {
			sign = -sign;
		}
		s++;
	}

	for (val = 0; *s && isdigit(*s); s++) {
		val = val * 10 + (*s - '0');
	}

	return val * sign;
}