#include<stdio.h>
int strlen(char str[])
{
   int count=0;
   int i=0;
   //char *ptr=str;
   while(str[i]!='\0')
   {
	 count++;
	 i++;
   }
   return count;
}
int main()
{
   char str[]="karthik";
   int x=strlen(str);
   printf("the length of the string is:%d\n",x);
   getch();
   return 0;
}