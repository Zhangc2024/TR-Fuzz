/* The fact that we can pass a funciton pointer as an argument,
 * and return a function pointer from a function allows a programmer
 * to avoid code redundancy.
 * Here is an example for qsort and comparator
 */

#include <stdio.h>
#include <stdlib.h>

/* A sample comparator function that is used for sorting and integer array in
 * ascending order.
 * To sort an array for any other data type and /or criteria, all we need to
 * do is write more compare functions... while using the same qsort()
*/


/* qsort()
 *
 * void qsort (
 *      void* base, size_t num, site_t size,
 *      int(*compar)(const void*, const void*)
 * );
 * Sorts the 'num' elements of the array pointed to by 'base', each element is
 * 'size' bytes long, using 'compar' function to determine the order
 *
 * refer to: http://www.cplusplus.com/reference/cstdlib/qsort/ 
 *
 */

int compare (const void *a, const void* b){
    return ( *(int*)a - *(int*)b );
}

int main(){
    int i;
    int values[] = {40, 10, 100, 90, 20, 25};
    int size_of_values = sizeof(values) / sizeof(values[0]);
    qsort(values, size_of_values, sizeof(int), compare);

    for(i = 0; i < size_of_values; i++)
        printf("%d ", values[i]);
    return 0;
}
