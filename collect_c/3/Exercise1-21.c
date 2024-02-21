#include<stdio.h>
#define TAB 8
#define MAX 1000

main(/*entab*/) {
	
	int sp, c, cont = 0;
	
	while ((c = getchar()) != EOF){
		if (c != ' ' && sp == 0) {
			putchar(c);	
			cont++;
		}
			
		if (c == ' ')
			sp++;
		
		if (c != ' ' && sp != 0){
			if ((cont + sp) == TAB)
				putchar('\t');
		 	else 
				while (sp > 0){
					putchar(' ');
					sp--;	
				}
				putchar(c);
			}
				
		if (c == '\n') {
			sp = cont = 0;
		}				
				
		if ((cont + sp) == TAB)
			cont = 0;
		}	
	}

