#include <stdio.h>
#include <math.h>

#include <stdint.h>
main(){
	int i,result;
	result=1;
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n.......First Question......\n");	
for(i=1;i<=8;i++)
	result=result*i;
printf("sizeof is %d\n",sizeof(uint8_t));

i=1;
result=1;
while(i<=8){
	result=result*i;
	i++;
}
printf("result is %d\n\n\n",result);
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
printf("......Second Question......\n");
int n,x;
double sum;
sum=0;
result=1;
printf("\n Enter value for x:\n");
scanf("%d",&x);
for(n=1;n<=7;n++){
		result=result*n;
		sum=pow(-1,n+1)*(pow(x,n))/result+sum;
	printf("Sum for %d th term: %lf\n",x,sum);
}	
	printf("\n\n General sum is = %lf\n",sum)	;


	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
	printf("\n********************\n");
printf("......Third Question......\n");	

i=0;

int a,y,z,result1;
printf("\n Enter value for a:\n");
scanf("%d",&a);
y=a;
printf("\ny %d\n",y);
result1=0;
while(a!=0){
	a=a/10;
	i++;
	printf("\ni %d\n",i);
}
n=0;
for(n=0;n<=i;n++){
	z=y%10;
	result1=result1+pow(2,n)*z;
	y=y/10;

}
printf("Result is %d",result1);


	
	
}
