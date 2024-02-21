#include <stdio.h>
 
 main() {
	
	printf ("The value of getchar() != EOF is 0 when the file ends, if not, the value is 1\n");
	while (getchar() != EOF)
		printf ("Value of getchar() != EOF: %i\n", getchar() != EOF);

 } 
