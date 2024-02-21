#include <stdio.h>
int sum(int N)
{
    int s=0;
    if(N==1)
    {
        s+=1; printf("1");
    }
    if(N>1)
    {
        printf("%i+", N);
        s=N+sum(N-1); 
    }
    return s;
}
int main()
{
    printf("=%i\n", sum(5));
    return 0;
}