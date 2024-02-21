#include <stdio.h>

int jami(int n)
{
int i, s=0;
for(i=1;i<=n;i++)
        {s+=i;}
return s;
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