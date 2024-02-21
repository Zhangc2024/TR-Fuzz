#include <stdio.h>
#include <string.h>

void rcomment(int c);
void in_comment(int d);
void echo_quote(int c);

int main() {
	int c;
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	while ((c = getchar()) != EOF)
		rcomment(c);
	return 0;
}

//Handle //... format of comment correctly
void rcomment(int c) {
	int d;
	if (c == '/') {
		if ((d = getchar()) == '*' || d == '/') {
			in_comment(d);
		} else {
			putchar(c);
			putchar(d);
		}
	} else if (c == '\'' || c == '"') {
		echo_quote(c);
	} else {
		putchar(c);
	}
}

void in_comment(int d) {
	int c, lastc;

	switch (d) {
	case '*':
		c = getchar();
		while ((lastc = c) != '*' || (c = getchar()) != '/')
			;
		break;
	case '/':
		while ((c = getchar()) != '\n')
			;
		break;
	}
}

void echo_quote(int d) {
	int c = d;
	putchar(c);
	do {
		putchar((c = getchar()));
		if (c == '\\')
			putchar(getchar());
	} while (c != d);
}

