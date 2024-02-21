#include <stdio.h>

/* Pointes and Arrays:
 * - Any operation that can be achieved by array subscripting can also be done
 *   with pointers.
 * - The pointer version will in general be faster.
 */
int main() {
    int x;
    int i;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *pa;

    pa = &a[0];
    /* sets pa to the element zero of a; that is, pa contains the address of
     * a[0]
     */

    x = *pa; // will copy the contents of a[0] into x

    /* If 'pa' points to a particular element off an array, then by definition
     * 'pa + 1' points to the next element, 'pa +i' points the 'i' elements
     * after 'pa' and 'pa - i' points 'i' elements before.
     *
     * If 'pa' points to a[0]
     * *(pa + 1)
     *
     * refers to the contents of a[1], 'pa + i' is the address of a[i], and
     * (pa +i) is the contents of a[i]
     */

    for (i = 0; i < 10; i++)
        printf("Index = %d, value = %d\n", i, *(pa + i));

    
    printf("\nWe can use array name as a pointer\n");
    for (i = 0; i < 10; i++)
        printf("%d\n", *(a + i));

    return 0;
}
