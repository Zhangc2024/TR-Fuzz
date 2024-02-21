#include<stdio.h>
void main()
{
   int n=5,i,j;
   clrscr();
   for(i=0;i<n;i++)
   {
	  for(j=0;j<2*n;j++)
	  {
		 if(j>=n-1-i&&j<=n-1+i)
		 {
			printf("*");
		 }
		 else
		 {
			printf(" ");
		 }
	  }
		 printf("\n");
   }
   getch();
}