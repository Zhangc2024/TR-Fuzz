#include<stdio.h>

int any(char s1[], char s2[]);

main() {
	
	int c, i;
	char s1[1000], s2[500];
	
	for (i = 0; (c = getchar()) != EOF && c!='\n'; ++i)
		s1[i] = c;
	
	for (i = 0; (c = getchar()) != EOF && c!='\n'; ++i)
		s2[i] = c;
	
	printf ("The position found is: %i", any(s1, s2));

}

int any(char s1[], char s2[]) {
	
	int i, j;

	for (i = 0; s1[i] != '\0'; ++i)
		for (j = 0; s2[j] != '\0'; ++j)
			if (s1[i] == s2[j])
				return i;				
	return -1;
	
}
