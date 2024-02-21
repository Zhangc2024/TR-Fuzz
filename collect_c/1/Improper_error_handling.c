
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
	char *foo;
	foo=(char *)malloc(sizeof(char));
	//the next line checks to see if malloc failed
	if (foo==0)
	{
		//We do nothing so we just ignore the error.
		printf("foo==0\n");
	}
	return 1;
}
