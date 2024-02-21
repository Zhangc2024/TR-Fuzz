#include<stdio.h>

void squeeze2(char s1[], char s2[]);

main() {
	
	int c, i;
	char s1[1000], s2[500];
	
	for (i = 0; (c = getchar()) != EOF && c!='\n'; ++i)
		s1[i] = c;
	
	for (i = 0; (c = getchar()) != EOF && c!='\n'; ++i)
		s2[i] = c;
	
	squeeze2(s1, s2);
	
	printf ("%s", s1);

}
 
void squeeze2(char s1[], char s2[]) {

	int i, j, o;
	
	for (o = 0; s2[o] != '\0'; o++) {
		for (i = j = 0; s1[i] != '\0'; i++)
			if (s1[i] != s2[o]) 
				s1[j++] = s1[i];
		s1[j] = '\0';
	}
	
}
