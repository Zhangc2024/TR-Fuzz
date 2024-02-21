#include<stdio.h>
#include<string.h>

void reverse(char s[]);

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int width) {

	int i, sign;
	
	if ((sign = n) < 0) /* record sign */
		n = -n; /* make n positive */
	i = 0;
	
	do { /* generate digits in reverse order */
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0); /* delete it */

	if (sign < 0)
		s[i++] = '-';
	
	for(; i < width; i++)
		s[i] = ' ';
	s[i] = '\0';
	
	reverse(s);
	
}

void reverse(char s[]) {

	int c, i, j;
	
	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c; 
	
}

main() {
	
	int n, w;
	char s[100];
	
	printf("Enter a number: ");
	scanf("%i", &n);
	
	printf("Enter the width: ");
	scanf("%i", &w);
	
	itoa(n, s, w);
	printf("%s\n", s);
	
}
