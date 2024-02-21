#include <stdio.h>
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
	i--;
	return i;
}

void dos(char s[], int len) {
	
	int i = 0, med, tras = 0, lant = 0, co, cos;
	med = co = cos = len/2;
	
	while (s[co] != ' ') {
		tras++;
		co--;
	}
	while (s[cos] != ' ') {
		lant++;
		cos++;
	}	
	if (tras < lant)
		med = co;
	else
		med = cos;

	while (i <= med && i <= len) {
		printf("%c", s[i]);
		i++;
	}

	printf ("\n");
 
	while (i <= len) {
		printf("%c", s[i]);
		i++;
	}
	
	printf ("\n");

}
