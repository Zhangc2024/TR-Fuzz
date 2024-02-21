#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand (time(NULL));
    int A[100],n,i,j;
    printf ("n = "); scanf ("%d",&n);
    for (i=0 ; i<n ; i++)
    {
        A[i]=rand()%38-12;
        printf("%d ",A[i]);
    }
    printf ("\n");
    int temp ;
    for (i=0 ; i<n ; i++)
    {
        for (j=i ; j<n ; j++)
        {
            if (A[i]<0)
            { A[i]=0 ;}                                                                                                                                                                                 
            if (A[i]>0)
            { A[i]=1 ;}
        }
    }
    
    for (i=0 ; i<n ; i++)
    {
        printf ("%d ", A[i]);
    }
    
    return 0;
}