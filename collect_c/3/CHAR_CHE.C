#include<stdio.h>
void check(char *c,char n)
{
   char *ptr=c;
   while(*ptr!='\0')
   {
	  if(*ptr==n)
	  {
		printf("present\n");
	  }else
	  {
		 printf("no\n");
	  }
	  ptr++;

   }
}
int main()
{
   char c[]="karthik";
   check(c,'r');
   getch();
   return 0;
}