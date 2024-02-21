#include <stdio.h>
int main()
{
    int A[100][100], n, m, i, j;
    printf("n="); scanf("%d", &n);
    printf("m="); scanf("%d", &m);
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    int s=0, B[100], k=0, t=0;
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            if (A[i][j]>0)
            {
                s+=A[i][j];
                B[k]=A[i][j];
                k++;
            }
            if (A[i][j]<0)
            {
                t=1;
                break;
            }
        }
        if (t==1)
        {
            { break; }
        }
    }
    for (i=0; i<k-1; i++)
    {
        printf("%d + ", B[i]);
    }
    printf("%d = %d\n", B[k-1], s);
    return 0;
}