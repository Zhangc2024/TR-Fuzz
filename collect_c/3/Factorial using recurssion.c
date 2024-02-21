//Factorial using recurssive function
#include<stdio.h>
#include<conio.h>
int factorial(int);
int main()
{
	int n,fact;
	printf("Enter the no.: ");
	scanf("%d",&n);
	
	fact=factorial(n);
	printf("The factorial of %d is %d",n,fact);
	
	getch();
	return 0;
}
int factorial(int n)
{
	if(n==1)
	{
		return 1;
	}
	else
	{
		return (n*factorial(n-1));
	}
}
