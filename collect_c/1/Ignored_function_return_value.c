#include <stdlib.h>

main ()
{
malloc(sizeof(int)*4);
/* If a functions return value is not checked, it could have failed without any warning. */
return 0;
}
