#include<stdio.h>
int main()
{
   int n=20,i,j;
   clrscr();
   for( i=0;i<n;i++)
   {
	 for( j=0;j<i+1;j++)
	 {
		printf("*");
	 }
	 printf("\n");
   }
   getch();
   return 0;
}