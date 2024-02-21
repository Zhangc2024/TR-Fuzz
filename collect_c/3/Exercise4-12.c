#include<stdio.h>

void itoa2(int n, char s[]) {

	static int i;
	
	if(s[i] == '\0')
		i = 0;
		 
	if (n < 0) {
		s[i++] = '-';
		n = -n;
	}

	if (n / 10)
		itoa2(n / 10, s);
	s[i++] = (n % 10 + '0');
	s[i] = '\0';
}

main() {
	
	char s[100];	
	int n;
	
	printf("Enter a number:\n");
	scanf("%i", &n);

	itoa2(n, s);
	printf("String number: %s\n", s);
		
	printf("\nEnter a number:\n");
	scanf("%i", &n);
	
	itoa2(n, s);
	printf("String number: %s\n", s);
	
}
