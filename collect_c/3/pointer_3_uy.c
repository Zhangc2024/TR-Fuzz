#include <stdio.h>
int main()
{
    int A[5]={10,20,30,40,50};
    int *sum=&A[5];
    *sum=0;
    for (int i=0; i<5; i++)
    {
        *sum+=A[i];
    }
    printf("sum=%i\n", *sum);
    for (int i=0; i<6; i++)
    {
        printf("%i ", A[i]);
    }
    printf("\n");
    return 0;
}