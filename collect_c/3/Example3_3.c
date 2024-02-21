#include<stdio.h>
#include <ctype.h>

int i;

/* atoi: convert s to integer; version 2 */
int atoi(char s[]) {
	
	extern int i;
	int n, sign;
	
	for (; isspace(s[i]); i++); /* skip white space */
		sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-') /* skip sign */
		i++;
	
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');

	return sign * n;
} 

main() {
	
	char s[100];
	int i, c;
	
	for (i = 0; (c = getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;
		
	for (i = 0; s[i] != '\0'; i++){
		if (isdigit(s[i]) || s[i] == '+' || s[i] == '-') {
			printf("Twice ");
			while (isdigit(s[i]) || s[i] == '+' || s[i] == '-'){	
    			printf("%c", s[i]);
    			i++;
			}
				printf(" is %d\n", 2 * atoi(s));	
		}
		
	}
}
