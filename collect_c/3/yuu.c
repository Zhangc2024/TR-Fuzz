#include <stdio.h>
char fun();
int main()
{
	char c=fun();
	printf("character is: %c", c);
}
char fun()
{
	return 'a';
}