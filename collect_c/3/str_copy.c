/* c-examples by A.Shtanyuk */
/* str_copy.c - string copy with pointers*/

#include <stdio.h>

int main()
{
   char str1[20]="A string";
   char str2[20];

   char * t=(char*)str2;
   char * p=(char*)str1;
	
   while(*t++=*p++);
   
   puts(str2);
   return 0;
}
