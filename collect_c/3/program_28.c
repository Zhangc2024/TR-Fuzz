// generate a fibonacci sequence

#include <stdio.h>

int main()
{
    int i, n;
    int t1 = 0;
    int t2 = 1;
    int nextTerm;

    printf("Please enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci sequence: ");

    for (i = 1; i <= n; i++)
    {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");

    return 0;
}