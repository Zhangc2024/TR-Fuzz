#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(0));
    int A[100], i, j, n;
    printf("n="); scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        A[i]=rand()%21-10;
        printf("%d ", A[i]);
    }
    int k=2; //printf("k="); scanf("%d", &k);
    for (j=1; j<=k; j++)
    {
        if (n%2!=0)
        {
            int temp1=A[n/2-1];
            for (int i=1; i>0; i--)
            {
                A[n/2-1]=A[0];
            }            
            A[0]=temp1;
            int temp2=A[n/2+1];
            for (int i=1; i>0; i--)
            {
                A[n/2+1]=A[n-1];
            }
            A[n-1]=temp2;
        }
        // if (n%2==0)
        // {
        //     int temp1=A[n/2-1];
        //     A[n/2-1]=A[0];
        //     A[0]=temp1;
        //     int temp2=A[n/2+1];
        //     A[n/2+1]=A[n-1];
        //     A[n-1]=temp2;
        // }
    }
    printf("\nNatija: ");
    for (i=0; i<n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}