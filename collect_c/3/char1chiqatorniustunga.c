#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(0));
    int A[100][100], i, j, n;
    printf("n="); scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            A[i][j]=rand()%10;
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("Output:\n");
    int temp;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (i==0 || j==0)
             printf("%d ", A[j][i]); 
            else
             printf("%d ", A[i][j]); 
        }
        printf("\n");
    }
    return 0;
}