#include <stdio.h>

int lower(int c);

int main() {

	int c;
	
	while ((c = getchar()) != EOF) 
	    putchar(lower(c));
	
}

int lower(int c) {
	
	return c >= 'A' && c <= 'Z' ? c = c + 'a' - 'A' : c;

}
