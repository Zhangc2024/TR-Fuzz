#include <stdio.h>

void a();
void b();

main()
{
	a();
	printf("h");	
}

void a()
{
	b();
}

void b()
{
	printf("b");
}
