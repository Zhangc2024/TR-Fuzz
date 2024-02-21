/*WAP to count no. of digits in a given no.*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int n,cnt=0;
	printf("Enter the no.");
	scanf("%d",&n);
	while(n!=0)
	{
		n=n/10;
		cnt++;
    }
	printf("The no. of digits in the given no. is %d",cnt);
	getch();
	return 0;
}

