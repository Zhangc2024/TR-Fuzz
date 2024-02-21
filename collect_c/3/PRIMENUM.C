   #include<stdio.h>
int main()
{
int n,i,count=0;
printf("enter the number\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
if(n%i==0)
{
count++;
}
}
if(count==2)
{
   printf("the no. %d is prime\n",n);
   }
 else
{
   printf("not prime\n");
}
 return 0;
}