#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void escape(char *s, const char t[]) {
	int i, j;
	i = j = 0;
	for (; t[i] != '\0'; i++) {
		switch (t[i]) {
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		default:
			s[j++] = t[i];
			break;
		}
	}

	s[j] = '\0';
}

/**
 * The official solution has minor mistakes when t[i] == '\\' and t[i+1] is neither 'n' nor 't':
 * First, it doesn't consider the case multiple '\\' come together
 * Second, it doesn't consider the case '\0' right after a '\\'
 */
void unescape(char *s, const char t[]) {
	int i, j;
	i = j = 0;
	while (t[i] != '\0') {
		if (t[i] == '\\') {
			switch (t[++i]) {
			case 'n':
				s[j++] = '\n';
				i++;
				break;
			case 't':
				s[j++] = '\t';
				i++;
				break;
			default:
				s[j++] = '\\';
				break;
			}
		} else
			s[j++] = t[i++];
	}

	s[j] = '\0';
}

int main() {
	char t[] = "\\n\\t\\\\tabc";
	char s[1000];
	unescape(s, t);
	printf("%s", s);
}
