#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char from[], int len);

main() {

	int len;
	char line[MAXLINE]; 

	while ((len = getline(line, MAXLINE)) >= 0)
		if (len > 0) {
			reverse(line, len);
	}

	return 0;
}
 
int getline(char s[],int lim) {
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;

	s[i] = '\0';
	
	return i;
}

void reverse(char from[], int len) {
	len -= 1;
	
	while (len >= 0) {
		printf("%c", from[len]);
		len--;
	}
	
	printf ("\n");
} 
