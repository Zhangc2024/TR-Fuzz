#include<stdio.h>
#include<string.h>

void escape(char s[], char t[]);
void inverse(char s[], char t[]);

main() {

	int c, i = 0;
	char t[220], s[150];
	
	printf("Enter a sentence with tabs and new lines please:\n");
	for (i = 0; (c = getchar()) != EOF; i++) {
		if (i > 60 && c == '\n') {
			s[i] = c;
			break;
		} else 
			s[i] = c;
	}
	s[i++] = '\n';
	s[i++] = '\0';

	escape(s, t);
	inverse(t, s);
	
} 

void escape(char s[], char t[]) {

	int i, j = 0;
	for (i = 0; s[i] != '\0'; i++) {
		switch (s[i]) {
			
			case '\n': t[j] = '\\'; t[j++] = '\\'; t[j++] = 'n'; break;
			case '\t': t[j] = '\\'; t[j++] = '\\'; t[j++] = 't'; break;
			default: t[j] = s[i]; j++; break;
		}
	}
	s[j++] = '\0';
	printf("\nscape: \n%s\n", t);
	
}

void inverse(char s[], char t[]) { 

	int i, j = 0, x = 0, l;
	for (i = 0; t[i] != '\0'; i++) {
		switch (t[i]) {
			
			case '\\': x = 1; break;
			case 't': if(x == 1) { s[j++] = '\t'; x = 0; } else s[j++] = t[i]; break;
			case 'n': if(x == 1) { s[j++] = '\n'; x = 0; } else s[j++] = t[i]; break;
			default : if(x == 1) s[j++] = '\\'; s[j++] = t[i]; x = 0;  break;
		}
	}
	s[j++] = '\0';
		
	printf("\ninverse: \n%s", s);
	
}
