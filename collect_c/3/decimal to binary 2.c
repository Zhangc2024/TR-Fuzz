#include <stdio.h>
#include <math.h>
main(){
	int a;
	int i=0,b;
	int sum=0,j=0;
	printf("Enter the value for a:");
	scanf("%d",&a);
	b=a;
	while(a!=-1){
		while(a!=0){
		i++;
		a/=2;
	}
	while(i!=0){
		sum=sum+(b%2)*pow(10,j);
		i--;
		j++;
		b/=2;
	}
	printf("\nbinary = %d\n",sum);
	 i=0;
	sum=0,j=0;
	printf("Enter the value for a:");
	scanf("%d",&a);
	b=a;
	}
}
