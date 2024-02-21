#include <stdio.h>
int main()
{
	int a,n,b=0,t; 
	printf("Raqamni kiriting: ");
	scanf("%d",&n); 
	t=n; 
	while(n>0) 
		{
			a=n%10; 
			b=b+a*a*a; 
			n=n/10; 
		}
	if(b==t) 
		{
			printf("%d armstrong raqam", t);
		}
	else
		{
			printf("%d armstrong raqam emas", t);
		}
return 0;
}
