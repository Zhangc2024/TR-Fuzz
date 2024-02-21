#include<stdio.h>
int main()
{
int a,b=1,c=0,d;
printf("I want to print n number of terms in fabonacci series. Where n= ");
scanf("%d",&a);
if(a==1)
printf("0");
else
{
printf("\nThe series is : 0, 1 ");
while(a>2)
{
d=b+c;
c=b;
b=d;
a--;
printf(",%d ",b);
}
}
return 0;
}
