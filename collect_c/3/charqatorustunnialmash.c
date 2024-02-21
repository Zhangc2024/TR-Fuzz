#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(0));
    int A[100][100], i, j, n, m;
    printf("n="); scanf("%d", &n);
    printf("m="); scanf("%d", &m);
    for (i=0; i<n; i++) 
    {
        for (j=0; j<m; j++)
        {
            A[i][j]=rand()%19-9;
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("Output:\n");
    for (i=0; i<n; i++) 
    {
        for (j=0; j<m; j++)
        {
            printf("%d ", A[j][i]);
        }
        printf("\n");
    }
        return 0;
}