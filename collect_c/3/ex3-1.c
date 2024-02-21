#include <stdio.h>

/* 
 * Exercise 3-1. modified binsearch. A version with only one test inside the loop 
 * Taken from C answer book. 
 *
 */

int binsearch(int x, int v[], int n);

int main()
{
    int v[]   = {10, 40, 50, 64, 75, 78, 89, 90, 91};
    int v_len = 9;

    printf("The index of value 64 in the array is %d\n", binsearch(64, v, v_len));

    return 0; // return SUCCESS
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low  = 0;
    high = n - 1;
    mid  = (low + high) / 2;

    while (low <= high && x != v[mid])
    {
        if (x < v[mid])

            high = mid - 1;
        else

            low  = mid + 1;

        mid = (low + high) / 2;
    }

    if (x == v[mid])
        return mid;
    else
        return -1;
}
