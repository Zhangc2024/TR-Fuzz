/*
 * htoi(s) that converts a string of hexadecimal digits (including an optional
 * 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 - 9, a - f, A - F.
 *
 * Max/min limits are not checked. 0xffffffff should be an error for signed int.
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int htoi(char *);

int
main(void)
{
	size_t i;

	char *s[] = {
		"beef",		/*        48,879 in decimal. */
		"BEEF",		/*        48,879 in decimal. */
		"0x12",		/*            18 in decimal. */
		"0X34",		/*            52 in decimal. */
		"0ead",		/*          3757 in decimal. */
		"002a",		/*            42 in decimal. */
		"2345",		/*          9029 in decimal. */
		"xead",		/*       Should be an error. */
	};

	for (i = 0; i < sizeof(s)/sizeof(s[0]); i++) {
		printf("%d\n", htoi(s[i]));
	}

	return (0);
}

int
htoi(char s[])
{
	int c;
	size_t i;
	size_t ind = 0;
	long value = 0;		/* Return zero on error. */

	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
		ind = 2;
	} else {
		for (i = 0; i < strlen(s); i++) {
			if (isxdigit(s[i]) == 0) {
				printf("Error\n");
				return (0);
			}
		}
	}

	for (; ind < strlen(s); ind++) {
		c = s[ind];
		if (isdigit(c)) {
			c -= '0';
		} else {
			c = tolower(c);
			c -= 'a' - 10;
		}

		value = 16 * value + c;
	}

	return ((int)value);
}
