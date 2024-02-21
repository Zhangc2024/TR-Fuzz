#include <stdio.h>

#define LOWER 0 /* lower temperature bound */
#define UPPER 300 /* upper temperature bound */
#define STEP 20 /* temperature step size */

int main() 
{
	int fahr = 0;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));

	return 0; 
}

