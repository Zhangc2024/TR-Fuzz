#include <stdio.h>

main ()
{
/* Using the value of an unitialized variable is not safe. */
int foo;
if (foo==0) printf("foo= 0");
return 0;
}

