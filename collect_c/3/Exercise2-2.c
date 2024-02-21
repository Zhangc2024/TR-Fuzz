#include<stdio.h>


int main() {

	int i, c, lim = 1000;
	char s[lim];

	for (i=0; (c = getchar()) != '\n'; ++i) {
		if (i < lim-1)
		if (c != EOF)
			s[i] = c;
		
	}
	s[i++] = '\0';
	printf("%s\n", s);
	
 }
