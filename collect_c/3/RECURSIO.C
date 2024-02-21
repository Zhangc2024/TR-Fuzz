#include<stdio.h>
int sum(int n);
int main()
{
  int n,x;
  printf("enter the number\n");
  scanf("%d",&n);
  x=sum(n);
  printf("the sum of first %d natural numbers is %d",n,x);
  getch();
  return 0;
}
int sum(int n)
{
  int res;
  if(n==1)
  {
   return 1;
  }
  else
  {
	res=sum(n-1)+n;
	return res;
  }
}
