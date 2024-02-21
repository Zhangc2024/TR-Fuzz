#include<stdio.h>
#include<string.h>

main () {
	
	int c, i, t, i2;
	char s[1000];
	
	for (i = 0; (c = getchar()) != EOF && c!= '\n'; ++i)
		s[i] = c;
	s[i++] = '\n';
	s[i] = '\0';

	printf("\nnormal: %i ", i - 1);
	printf("trim: %i\n\n", trim(s) == -1 ? 0 : trim(s));
	
	for(i = 0; i <= trim(s); i++)
		printf("%c", s[i]);
	printf("\n");
	
}

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[]) {
	
	int n;

	for (n = strlen(s)-1; n >= 0; n--)
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			break;
	
	s[n+1] = '\0';
	
	return n;
} 
