/*
 * squeezestr
 * Write an alternate version of squeeze(s1, s2) that deletes each character
 * in s1 that matches any character in the string s1.
 */

#include <stdio.h>

void squeeze(char [], int);
void squeezestr(char [], char []);

int
main(void)
{
	char str1[] = "Hello, World!";
	int ch1 = 'l';

	char str2[] = "Hello, World!";
	char sch2[] = "dHrl";

	char str3[] = "Hello, World!";
	char sch3[] = "";

	printf("%s\n", str1);
	squeeze(str1, ch1);
	printf("Remove this character: %c\n", ch1);
	printf("%s\n\n", str1);

	printf("%s\n", str2);
	squeezestr(str2, sch2);
	printf("Remove these characters: %s\n", sch2);
	printf("%s\n\n", str2);

	printf("%s\n", str3);
	squeezestr(str3, sch3);
	printf("Remove no characters\n");
	printf("%s\n", str3);

	return (0);
}

void
squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}

void
squeezestr(char s1[], char s2[])
{
	int i, j, k;

	j = 0;
	for (i = 0; s1[i] != '\0'; i++) {
		for (k = 0; s2[k] != '\0'; k++) {
			if (s1[i] == s2[k]) {
				i++;
				k = 0;
			}
		}
		s1[j++] = s1[i];
	}
	s1[j] = '\0';
}
