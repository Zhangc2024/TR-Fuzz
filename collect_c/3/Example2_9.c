#include<stdio.h>

void squeeze(char s[], int c);

main() {
	
	int c, i;
	char s[1000];
	
	for (i = 0; (c = getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;
	
	squeeze(s, 'a');
	
	printf ("%s", s);

}
 
 /* squeeze: delete all c from s */
void squeeze(char s[], int c) {

	int i, j;
	
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
		s[j++] = s[i];
	
	s[j] = '\0';
	
} 
