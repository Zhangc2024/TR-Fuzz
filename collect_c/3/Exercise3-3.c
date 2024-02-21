#include<stdio.h>
#include<ctype.h>

void expand(char s1[], char s2[]) { 
	
	int i, in, a = 1, k, p; 
	char u, v; 
	
	for (i = 0; s1[i] != '\0'; i++) { //sorry for the mess ^_^'
		if(s1[i+1] == '-' && (s1[i] < s1[i+2] && ((isdigit(s1[i]) && isdigit(s1[i+2])) || (isalpha(s1[i]) && 
		 isalpha(s1[i+2]) && ((islower(s1[i]) && islower(s1[i+2])) || (isupper(s1[i]) && isupper(s1[i+2])))))) ||
		 (s1[i] == '-' && (s1[i-1] < s1[i+1] && ((isdigit(s1[i-1]) && isdigit(s1[i+1])) || (isalpha(s1[i-1]) && 
		 isalpha(s1[i+1]) && ((islower(s1[i-1]) && islower(s1[i+1])) || (isupper(s1[i-1]) && isupper(s1[i+1]))))))))
			in = 1;
		  else 
			in = 0;
		if(((s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z') || isdigit(s1[i])) && in == 1) {
			p = i + 1;
			if(s1[p++] == '-') {
				u = s1[p];
				for(v = s1[i]; v != u; v++)
					s2[k++] = v;
				a = 0;
			} 
		} else if (a)
			s2[k++] = s1[i];
		  else {
			a = 1;
		  }		
	}
	s2[k++] = '\0';
	printf("\n%s", s2);
	
}

main() {

	int c, i = 0;
	char s1[500], s2[1000];

	for (i = 0; (c = getchar()) != EOF && c != '\n' ; i++) 
			s1[i] = c;
	s1[i++] = '\n';
	s1[i++] = '\0';

	expand(s1, s2);

} 
