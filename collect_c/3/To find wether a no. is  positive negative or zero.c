/*To find wether a no. is  positive negative or zero*/
#include<stdio.h>
#include<conio.h>

int main()
{
	int n;
	printf("Enter the number to be checked");
	scanf("%d",&n);
	if(n>0)
		printf("%d is a positive no.",n);
	else if(n<0)
		printf("%d is a negative no.",n);
	else
		printf("%d is zero",n);
	getch();
	return 0;
}
