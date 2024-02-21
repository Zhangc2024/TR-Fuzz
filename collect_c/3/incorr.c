/* c-examples by A.A.Shtanyuk */
/* incorr.c - incorrect use of function */

#include <stdio.h>

int fa() { puts("fa"); return 1;}
int fb() { puts("fb"); return 2;}
int fc() { puts("fc"); return 3; }

void fun( int a, int b, int c)
{
	printf("%d %d %d",a,b,c);
}
int main()
{
	fun(fa(),fb(),fc()); // call order unknown!
	return 0;
}
