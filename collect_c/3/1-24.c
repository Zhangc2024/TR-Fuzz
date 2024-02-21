#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void in_comment(int d);
void in_quote(int c);
void search(int c);

int brace, brack, paren;
int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int c;

	while ((c = getchar()) != EOF) {
	if (c == '/' && ((c = getchar()) == '*' || c == '/'))
			in_comment(c);
		else if (c == '\'' || c == '"')
			in_quote(c);
		else
			search(c);
	//check syntax
		if (brace < 0) {
			puts("Braces Mismatch.");
			brace = 0;
		}
		if (brack < 0) {
			puts("Brackets Mismatch.");
			brack = 0;
		}
		if (paren < 0) {
			puts("Parenthesis Mismatch.");
			paren = 0;
		}

	}

	//check sintax
	if (brace > 0) {
		puts("Braces Mismatch.");
		return 1;
	}
	if (brack > 0) {
		puts("Brackets Mismatch.");
		return 1;

	}
	if (paren > 0) {
		puts("Parenthesis Mismatch.");
		return 1;
	}
	return 0;
}

void search(int c) {
	switch (c) {
	case '{':
		brace++;
		break;
	case '}':
		brace--;
		break;
	case '(':
		paren++;
		break;
	case ')':
		paren--;
		break;
	case '[':
		brack++;
		break;
	case ']':
		brack--;
		break;
	default:
		break;
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

void in_quote(int d) {
	int c;
	do {
		if ((c = getchar()) == '/')
			getchar();
	} while (c != d);
}
