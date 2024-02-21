#include <stdio.h>
#include <math.h>

/* itoa: covert n to characters in s; recursive */

void itoa(int n, char s[])
{
	static int i;
	
	if (n / 10)
		itoa (n/10, s);
	else {
		i = 0;
		if (n < 0)
			s[i++] = '-';
	}
	s[i++] = abs(n) % 10 + '0';
	s[i] = '\0';
}

main(){
	int n;
	char s[4];
	n = 123;
	itoa(n, s);
	printf ("%s", s);
}
