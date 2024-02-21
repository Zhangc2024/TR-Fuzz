#include <stdio.h>

int jami(int n)
{
int s=n;
return s+jami(n-1);
}

void tgachajami(int n)
{
        if(n==1)
        {
        tgachajami(n-1);
        printf("%d",n);
        }
        if(n>0 && n!=1)
        {
        tgachajami(n-1);
        printf("+%d",n);
        }
}

void main()
{
int k;
scanf("%d",&k);
tgachajami(k);
printf("=%d",jami(k));
}