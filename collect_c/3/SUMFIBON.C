#include<stdio.h>
int fibonacci(int n);
int main()
{
   int n;
   printf("enter the number\n");
   scanf("%d",&n);
   printf("the sum of fibonacci series till %d is %d\n",n,fibonacci(n));
   getch();
   return 0;
}
int fibonacci(int n)
{
   int a=0,b=1,c=0,i;
   for(i=0;i<=n;i++)
   {
	 c=a+b;
	 a=b;
	 b=c;
   }
   return c;
}