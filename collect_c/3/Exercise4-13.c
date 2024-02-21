#include<stdio.h>
#include<string.h>

void reverse(char [], char);

void itoa(int n, char s[]) {

	int i, sign;
	
	if ((sign = n) < 0) 
		n = -n; 
	i = 0;
	
	do { 
		s[i++] = n % 10 + '0'; 
	} while ((n /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	
	reverse(s, s[(strlen(s))]);
	
}

void reverse(char s[], char p) {
	
	static int i, j;
	int f;
	f = strlen(s);
	
	if(p == '\0')
		i = 0, j = 0;
		
	if(i != f)
		reverse(s, s[i++]);
	if(p != '\0') 
		s[j++] = p;
	s[j] == '\0';

}

main() {
	
	char s[100];	
	int n;
	
	printf("Enter a number:\n");
	scanf("%i", &n);
	
	itoa(n, s);
	printf("String number: %s\n", s);
	
	printf("\nEnter a number:\n");
	scanf("%i", &n);
	
	itoa(n, s);
	printf("String number: %s\n", s);
}
