#include <stdio.h>

main(){
	
	int choice;
	double x,y,result;

	printf("***************\n");
	printf("*1. Sum       *\n");
	printf("*2. Substract *\n");
	printf("*3. Multiply  *\n");
	printf("*4. Divide    *\n");
	printf("***************\n");

	printf("Enter your choice:\n");
	scanf("%d",&choice);
	printf("Enter value for x and y:\n");
	scanf("%lf%lf",&x,&y);
	
	switch(choice){
		case 1:
			result=x+y;
			printf("%lf + %lf = %lf",x,y,result);
			break;
		case 2:
			result=x-y;	
			printf("%lf - %lf = %lf",x,y,result);
			break;	
		case 3:
			result=x*y;	
			printf("%lf * %lf = %lf",x,y,result);
			break;	
		case 4:
			result=x/y;	
			printf("%lf /y %lf = %lf",x,y,result);
			break;	
		default:
			printf("Wrong choice");	
	}
	
	
}
