#include <stdio.h>
int main()
{
    int A[100], n;
    printf("n="); scanf("%i", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%i", &A[i]);
    }
    int *max=A, *min=A;
    for (int i=1; i<n; i++)
    {
        if (A[i]>*max)
        { max=&A[i]; }
        if (A[i]<*min)
        { min=&A[i]; }
    }
    printf("max=%i\tmin=%i\n", *max, *min);
    int *temp=&A[n];
    *temp=*max;
    *max=*min;
    *min=*temp;
    for (int i=0; i<n; i++)
    {
        printf("%i ", A[i]);
    }
    puts("");
    return 0;
}