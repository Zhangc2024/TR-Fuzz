#include <stdio.h>

int main(void) {
unsigned long long int n,i,j,a[10000],c=0;
scanf("%d",&n);
for(i=0;i<n;i++)
{
    scanf("%d",&a[i]);
}
for(i=0;i<n-1;i++)
{
    for(j=i+1;j<n;j++)
    {
        if(a[i]>a[j])
        c++;
    }
}
printf("%d",c);
	return 0;
}
