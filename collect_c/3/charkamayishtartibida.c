#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int A[100], n, i;
    printf("n="); scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        A[i]=rand()%19-9;
        printf("%d ", A[i]);
    }

    printf("\n");
    int temp, j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (A[j]<A[i])
            {
                temp=A[j];
                A[j]=A[i];
                A[i]=temp;  
            }
        }
    }
    
    printf("Kamayish tartibida: ");
    for (i=0; i<n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}