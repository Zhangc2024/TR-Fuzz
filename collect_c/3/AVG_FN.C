#include<stdio.h>
float avg(int a,int b,int c);
void main()
{
   float average;
   clrscr();
   average=avg(3,3,3);
   printf("the average of three no.s is %.0f\n",average);
   getch();
}
float avg(int a,int b,int c)
{
   float average;
   average=(a+b+c)/3;
   return average;   
}




