#include <stdio.h>

int binsearch(int x, int v[], int n);

main()
{
    /* search for 19 */
    int v[] = {1, 4, 10, 19, 23, 54, 97};
    int x = 19, n = 6, loc = binsearch(x, v, n);
    printf("binsearch(%d, v, %d) = %d\n", x, n, loc);

    /* search for 54 */
    x = 54;
    loc = binsearch(x, v, n);
    printf("binsearch(%d, v, %d) = %d\n", x, n, loc);

    /* search for 3 */
    x = 3;
    loc = binsearch(x, v, n);
    printf("binsearch(%d, v, %d) = %d\n", x, n, loc);

    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low+high+1) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid;
    }
    return x == v[low] ? low : -1;
}
