#include <stdio.h>
int main()
{
    int A[100], n;
    printf("n="); scanf("%i", &n);
    int *p=A, i;
    for (i=0; i<n; i++)
    {
        scanf("%i", (p+i)); // &A[i]=p+i
    }
    printf("Natija: ");
    for (i=0; i<n; i++)
    {
        printf("%i ", *(p+i));
    }
    printf("\n");
    return 0;
}