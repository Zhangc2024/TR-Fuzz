#include<stdio.h>

main(){

	int c;
	
	while((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t') {
			putchar(' ');
			while((c = getchar()) == ' ');
		}
		putchar(c);
	}
}
