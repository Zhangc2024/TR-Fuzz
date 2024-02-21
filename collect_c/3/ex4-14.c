/* Define a macro swap(t, x, y) that interchanges two arguments
 * of type t
 */

#include <stdio.h>

#define swap(t, x, y) { \
    t temp;             \
    temp = x;           \
    x = y;              \
    y = temp;           \
}

int main()
{
    int x = 10, y = 20;

    swap(int, x, y);

    printf("x is %d\n", x);
    printf("y is %d\n", y);

    return 0;// return SUCCESS
}
