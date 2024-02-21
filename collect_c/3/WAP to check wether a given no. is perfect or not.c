/*WAP to check wether a given no. is perfect or not*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int n,i=1,sum=0;
	printf("Enter a no.");
	scanf("%d",&n);
	while(i<n)
	{
		if(n%i==0)
           sum+=i;
		i++;
	}
	if(sum==n)
       printf("%d is a perfect no.",i);
    else
	   printf("%d is not a perfect no.",i);   
	getch();
	return 0;		 
}

