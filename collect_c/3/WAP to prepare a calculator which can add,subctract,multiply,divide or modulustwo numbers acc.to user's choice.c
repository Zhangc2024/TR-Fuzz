/*WAP to prepare a calculator which can add,subctract,multiply,divide or modulustwo numbers acc.to user's choice*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	float a,b;
	int choice;
		
	printf("1.\tAddition\n2.\tSubctraction\n3.\tMultiplication\n4.\tDivision\n5.\tSquare Root\
	\n6.\tExit\nEnter your choice:");
	scanf("%d",&choice);
	while(choice!=6)
	{
	if(choice!=6)
	{
	
	switch(choice)
	{
		case 1:
			printf("Enter two numbers");
			scanf("%f%f",&a,&b);
			printf("Addition result is %f",a+b);
			break;
		case 2:
			printf("Enter two numbers");
			scanf("%f%f",&a,&b);
			printf("Subctraction result is %f",a-b);
			break;
		case 3:
			printf("Enter two numbers");
			scanf("%f%f",&a,&b);
			printf("Multiplication result is %f",a*b);
			break;
		case 4:
			printf("Enter two numbers");
			scanf("%f%f",&a,&b);
			printf("Division result is %f",a/b);
			break;
		case 5:
			printf("Enter The no. for Square root");
			scanf("%d",&a);
			printf("root result is %f",sqrt(a));
			break;
			
		default:
			printf("Invalid Input");
					
	}
	}
	else
		printf("Good Bye");
	}
	getch();
	return 0;
}
