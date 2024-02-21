#include <stdio.h>
#include <string.h> // strstr

#define MAX 80

char linea[MAX];
int saca();

main() {/* de que hablas
  
xd*/extern char linea[];
	int ignore = 0;
	int l = 0, i, fi, done, peace;
	
	while ((l = saca()) == 0) { 
		if (strstr(linea, "/*") != NULL) { // check for substring
    		ignore = 1;
    	}
    	for (i = 0; ignore && linea[i] != '/' && done == 0; i++) {
    		printf ("%c", linea[i]);
    		fi = 1;
    	}
    	if (fi) {
			printf ("\n");
			fi = 0;
			done = 1;
    	}
    	if (!ignore) {
    		printf("%s\n", linea);
    	}
    	if (strstr(linea, "*/") != NULL) {
    		ignore = 0;
    		done = 0;
    		for (i = 0; linea[i] != '/'; i++);
    		i++;
    		while (linea[i] != '\0') {
				printf ("%c", linea[i]);
				i++;
   			}
   			printf("\n");
    	}
    	
  	}
  return 0;
}

int saca() {
	
	extern char linea[];
	int c, i = 0;
	int sc = 0;

	for (; i < MAX - 1 && (c = getchar()) != EOF && c != '\n';) {
		if (c == '/') {
    		sc++;
    	if (sc == 2) {
		i--;
		}
  	  } else if (sc < 2) { 
    	sc = 0;
    	}
    	if (sc < 2) {
    		linea[i++] = c;
    	}	
	}
  	
	linea[i] = '\0'; // caracter de terminacion de string
	
	return c == EOF;
}

