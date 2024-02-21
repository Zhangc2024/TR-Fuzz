#include <stdio.h>
#include <math.h>
main(){

	printf("\n.......First Question......\n");	
	int i,x,y,gcd;
	i=1;
	printf("\nEnter value for x and y\n");
	scanf("%d%d",&x,&y);
	while(i<=x && i<=y){
		if(x%i==0 && y%i==0)
			gcd=i;
	i++;	
	}
	printf("GCD is %d\n",gcd);
	
	
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n.......Second Question......\n");	
	
x=0,y=0;
	printf("\nEnter value for x\n");
	scanf("%d",&x);
	for(i=1;i<x;i++){
		if(x%i==0){
			y=y+i;
			printf("%d's multipliers are: %d\t",x,i);
		}
			
	}
	if(x==y)
		printf("\n%d is Perfect number.",x);
	else
		printf("\n%d is not Perfect number.",x);
	
	
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n.......Third Question......\n");	
	
	x=0,i=0,y=0;
	printf("\nEnter value for x:");
	scanf("%d",&x);
	y=x;
	int x1,z;
	x1=x;
	while(x!=0){
		x=x/10;
		i++;
	}
	z=0;
	for(;i!=0;i--){
		z=y%10*pow(10,i-1)+z;
		y=y/10;
		
	}	
	if(x1==z)
		printf("\n%d is palindromic number\n",x1);
	else
		printf("\n%d is not palindromic number\n",x1);	
	
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n.......Fourth Question......\n");			
	
	x=0,i=0,z=0,y=0;
	printf("Enter value for x:");
	scanf("%d",&x);
	y=0;
	z=x;
	while(x!=0){
		y=pow(x%10,3)+y;
		x=x/10;
	}
	if(z==y)
		printf("\n%d is Armstrong number.",z);
	else
		printf("\n%d is not Armstrong number.",z);		
		
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n.......Fifth Question......\n");		

 	x=0,i=0;
	printf("Enter value for x:");
	scanf("%d",&x);
y=0;
int t;

	while(x!=0){
		y=y+x%10;
		x=x/10;
	}
	printf("\nSum up all individual digits of a number is %d",y);
	
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n.......Sixth Question......\n");	
	
	x=0,y=0,z=0;
	
	printf("Enter value for x:");
	scanf("%d",&x);
	y=x;
	t=x;
	while(x!=0){
		x=x/10;
		i++;
	}
	while(i!=0){
		z=(y%10)*pow(10,i-1)+z;
		i--;
		y/=10;
		
	}
	printf("Reversed number of %d is %d",t,z);

		
	
}
