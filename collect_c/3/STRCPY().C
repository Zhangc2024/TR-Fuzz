#include<stdio.h>
int main()
{
   int i=0;
   char s1[]="Ertugrul bey";
   char s2[20];
   while(s1[i]!='\0')
   {
	  s2[i]=s1[i];
	  i++;
   }
   s2[i]='\0';
   printf("s2 after copied by s1:%s\n",s2);
   getch();
   return 0;
}