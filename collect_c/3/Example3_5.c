#include <string.h>
#include <stdio.h>

/* reverse: reverse string s in place */
char *reverse(char s[]) {

	int c, i, j;
	
	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c; 

	
	return s;
} 

main() {
	
	int i, c;
	char s[1000];

	for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	s[i] = '\0';
	
	printf("\n%s\n", reverse(s));

}
