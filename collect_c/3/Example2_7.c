#include <stdio.h>

int function_tolower(int c);

int main() {

	int c;
	
	while ((c = getchar()) != EOF) 
	    putchar(function_tolower(c));
	
}

 /* lower: convert c to lower case; ASCII only */
int function_tolower(int c) {

	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;

} 

