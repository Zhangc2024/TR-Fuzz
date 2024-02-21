#include <stdio.h>
#include <ctype.h>

int i; 

int function_atoi(char s[]) {

	extern int i;
	int n;
	n = 0;
	
	while (!isdigit(s[i])) //to catch just numbers
		i++;
		
	for (; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');
		
	return n;

}

main() {
	
	char s[100];
	int i, c;
	
	for (i = 0; (c = getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;
		
	for (i = 0; s[i] != '\0'; i++){
		if (isdigit(s[i])) {
			printf("Twice ");
			while (isdigit(s[i])){	
    			printf("%c", s[i]);
    			i++;
			}
				printf(" is %d\n", 2 * function_atoi(s));	
		}
		
	}
}

