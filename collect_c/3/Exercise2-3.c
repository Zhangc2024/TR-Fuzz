#include <stdio.h>
#include <ctype.h>

int i; 

int htoi(char s[]) {

	extern int i;
	int n, hex;
	n = 0;
	
	while (!isdigit(s[i]) && !(s[i] >= 'A' && s[i] <= 'F'))
		i++;
		
	for (; isdigit(s[i]) || (s[i] >= 'A' && s[i] <= 'F'); ++i) {
		if (isdigit(s[i]))
			hex = s[i] - '0';
		else
			hex = s[i] - 'A' + 10; 
		n = 16 * n + hex;
	}
		
	return n;

}

main() {
	
	char s[1000];
	int i, c, j;
	
	for (i = 0; (c = getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;
	
	j = i;
	for (i = 0; i != j ; ++i)
		if (s[i] >= 'a' && s[i] <= 'f')
			s[i] = toupper(s[i]);
		
	for (i = 0; s[i] != '\0'; i++){
		if (isdigit(s[i]) || (s[i] >= 'A' && s[i] <= 'F')) {
			printf("Hexadecimal string: ");
			while (isdigit(s[i]) || (s[i] >= 'A' && s[i] <= 'F')){	
    			printf("%c", s[i]);
    			i++;
			}
				printf(", Decimal number %d\n", htoi(s));	
		}
	}
}
