#include<stdio.h>
#include<string.h>

void reverse(char s[]);

void itob(int n, char s[], int base) {

	int i, sign, b;

	if ((sign = n) < 0) 
		n = -n; 
	i = 0;
	
	do { 
		s[i++] = n % base + '0'; 
	} while ((n /= base) > 0); 

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
			
	reverse(s);
	
}

void reverse(char s[]) {

	int c, i, j;
	
	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c; 
	
}

main() {
	
	int n, b;
	char s[100];
	
	printf("Enter a number: ");
	scanf("%i", &n);
	
	printf("Enter the base: ");
	scanf("%i", &b);
	
	itoa(n, s, b);
	printf("\n%s\n", s);
	
}

