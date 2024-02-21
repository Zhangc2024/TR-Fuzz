#include<stdio.h>
#define TAB 8

main(/*detab*/) {
	
	int c, cont = 0;
	
	while ((c = getchar()) != EOF) {
		if (c != '\t') {
			putchar(c);
			if (c != '\n')
			cont++;
			if (c == '\n')
			cont = 0;
		}
		if (cont == TAB)
			cont = 0;
			
		if (c == '\t') {
			while (cont != TAB) {
				putchar (' ');
				cont++;		
			}
			cont = 0;
		}
	}		
}	
