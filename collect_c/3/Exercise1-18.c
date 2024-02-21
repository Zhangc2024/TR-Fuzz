#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void dos(char s[], int len);

main() {

	int len;
	char line[MAXLINE]; 

	while ((len = getline(line, MAXLINE)) >= 0)
		if (len > 0) {
			dos(line, len);
	}

	return 0;
}
 
int getline(char s[],int lim) {
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;
	
	return i;
}

void dos(char s[], int len) {
	
	int j = 0, i = len, f = 0;
	
	for (j = 0; j < i ; ++j) {
	if (isspace(s[j])) 
		f++;
	if (!isspace(s[j])) 
		f = 0;		
	}
	
	len -= f;	
	len -= 1;
	i = 0;
	
	while (i <= len) {
		printf("%c", s[i]);
		i++;
	}
	
	printf ("\n");
}
