#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "day"; 

main() {
	
	char line[MAXLINE];
	int found = 0;
	
	while (getline(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	
	return found;
}

int getline(char s[], int lim) {
	
	int c, i;
	i = 0;
	
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	
	if (c == '\n')
		s[i++] = c; 
	
	s[i] = '\0';
	
	return i;
}

int strindex(char s[], char t[]) {
	
	int i, j, k;

	for (i = strlen(s); i != 0; i--) {
		for (j = i, k = (strlen(t) - 1); k != 0 && s[j] == t[k]; j--, k--);
		if (k == 0) 
			return (i - strlen(t) + 1);	
	}

	return -1;
}

