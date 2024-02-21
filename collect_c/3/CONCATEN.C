#include<stdio.h>
int main()
{
   char s1[]="karthik";
   char s2[]="bhai";
   int i;
   int l1=strlen(s1);
   int l2=strlen(s2);
   for(i=0;i<=l2;i++)
   {
	  s1[l1+i]=s2[i];
	}
   printf("the string after concatenation:%s",s1);
   getch();
   return 0;
}