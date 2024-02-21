/* Example in section 1.5.1 */

#include <stdio.h>

/*copy input to output; 2nd version */
main()
{
    int c; 
    
    while ((c = getchar()) != EOF) 
	putchar(c); 
}
