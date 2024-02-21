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
    printf("To'g'ri diagonal elementlari:"); for (i=0; i<n; i++)
    {
        int temp_2;
        temp_2=A[i][n-i-1];
        A[0][0]=A[n][n];
        A[n][n]=temp_2;
        printf("%d ", A[i][j]);
    }
    printf("\nTeskari diagonal elementlari:");
    for (i=0; i<n; i++)
    {
        int temp_1;
        temp_1=A[0][0];
        A[0][0]=A[n][n];
        A[n][n]=temp_1;
        printf("%d ", A[i][n-1-i]);
    }
    printf("\n");
    return 0;
}