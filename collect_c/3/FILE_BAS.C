#include<stdio.h>
int main()
{
   FILE *ptr;
   char c;
   ptr=fopen("karthik.txt","r");
  // c=fgetc(ptr);
  // printf("the first letter of the file:%c\n",c);
  if(ptr==NULL)
  {
   printf("file does not exist");
  }
   getch();
   return 0;
}

