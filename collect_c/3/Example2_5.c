#include<stdio.h>

int main() {

	int i, c, lim = 1000;
	char s[lim];

	for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;  
	
	s[i++] = '\0';
	printf("%s\n", s);
	
 }
