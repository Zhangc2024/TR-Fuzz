#include<stdio.h>
#include<math.h>
int main()
{
	int a,n,s=0;
	printf("Enter a value ");
	scanf("%d",&n);
	for(a=1;a<=n;a++)
	{
		s=s+pow(a,a);
	}
	printf("Result= %d",s);
	return 0;
}
