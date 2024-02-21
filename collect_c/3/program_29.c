// generate fibonacci sequence upto a certain number

#include <stdio.h>

int main()
{
    int n;
    int t1 = 0, t2 = 1;
    int nextTerm = 0;

    printf("Please enter a positive number: ");
    scanf("%d", &n);

    printf("Fibonacci series: %d %d ", t1, t2);
    nextTerm = t1 + t2;

    while (nextTerm < n)
    {
        printf("%d ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }

    printf("\n");

    return 0;
}