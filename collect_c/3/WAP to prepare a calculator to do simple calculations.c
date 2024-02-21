/*WAP to prepare a calculator to do simple calculations*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    char sign;
    float a,b;
    printf("Enter a sign(+-*/%)");
    scanf("%c",&sign);
    printf("Enter two numbers:");
    scanf("%f%f",&a,&b);
	switch (sign)
	{
	    case '+':
	        printf("Sum=%f",a+b);
	        break;
	    case '-':
	        printf("Difference=%f",a-b);
	        break;
	    case '*':
	        printf("Product=%f",a*b);
	        break;
	    case '/':
	        printf("Quotient=%f",a/b);
	        break;
	    case '%':
	        printf("Remainer=%d",(int)a%(int)b);
	        break;  
	    default:
	        printf("Invalid Operator");
	        break;
    }
	getch();
    return 0;
}
