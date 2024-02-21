/* similar to qsort() we can write our own functions that can be used for any
 * data type and can do different tasks without code redunduncy.
 * Here is an example search function
 */

#include <stdio.h>
#include <stdbool.h>

/* compare function that is used for searching an integer array */
bool compare (const void *a, const void *b){
    return ( *(int*) a == *(int*)b );
}

/* search() function:
 * - note: we use void pointers so that the function can be called by passing
 *   a pointer of any type
 */
int search(
    void* arr, int array_size, int element_size, void *x,
    bool compare(const void*, const void*)
){
    /* since char takes one byte, we can use char pointer for any type.
     * to perform our pointer arithmetic correctly, we need to multiply index
     * with size of an array element 'element_size'
     */

    char* ptr = (char *)arr;

    int i;
    for (i = 0; i < array_size; i++)
        if (compare(ptr + i * element_size, x))
            return i;

    // if element wasn't found
    return -1;
}

int main(){
    int arr[] = {20, 50, 70, 90, 60};
    int n = sizeof(arr) / sizeof(*arr);
    int x = 90;
    printf("index of %d ", search(arr, n, sizeof(int), &x, compare));
    return 0;
}
