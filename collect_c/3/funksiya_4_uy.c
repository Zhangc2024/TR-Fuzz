#include <stdio.h>
int tub(int n, int m)
{
    if (n==1) 
    { return 1; }
    else if (n>1 && m>1)
    {
        if (n%m==0)
        { return 1; }
        else 
        { tub(n, m-1); }
    }
    else
    { return 0; }
}
int main()
{
    int son;
    printf("son="); scanf("%i", &son);
    if (tub(son, son/2)==0)
    { puts("tub son"); }
    else 
    { puts("tub son emas"); }
    return 0;
}