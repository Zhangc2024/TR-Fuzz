#include<stdio.h>
int main()
{
	int n,son,x,sum=0; 
	printf("Sonni kiriting: ");
	scanf("%d",&n); 
	while(n>0) 
		{
			x=n%10; 
			sum=sum+x; 
			n=n/10; 
		}
		printf("Sonning raqamlari yig'indisi = %d",sum); 
	return 0;
}

