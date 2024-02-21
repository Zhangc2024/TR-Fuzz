#include<stdio.h>
int positive(int *arr,int n)
{
   int pos_count,neg_count,i;
   for(i=0;i<n;i++)
   {
	  if(arr[i]>0)
	  {
		pos_count++;
	  }else if(arr[i]<0)
	  {
	   neg_count++;
   }
   return pos_count;
}
int main()
{
   int arr[]={1,2,-3,-4,5,6,-7,8},x;
   x=positive(arr,8);
   printf("the number of positive integers in this array is:%d\n",x);
   getch();
   return 0;
}