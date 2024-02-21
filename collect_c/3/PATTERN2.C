#include<stdio.h>
void main()
{
   int n=5,i,j;
   clrscr();
   for(i=0;i<n;i++)
   {
	  for(j=0;j<n;j++)
	  {
		 if(i+j>=n-1)
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