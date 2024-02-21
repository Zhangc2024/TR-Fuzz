#include<stdio.h>
int main()
{
   FILE *ptr;
   int name1,name2,sal1,sal2;
   printf("enter the name of emlpoyee1\n");
   scanf("%d",&name1);
   printf("enter the  salary of emlpoyee1\n");
   scanf("%d",&sal1);
   printf("enter the name of emlpoyee2\n");
   scanf("%d",&name2);
   printf("enter the  salary of emlpoyee2\n");
   scanf("%d",&sal2);
   ptr=fopen("output.txt","w");
   fprintf(ptr,"%d,%d\n",name1,sal1);
   fprintf(ptr,"%d,%d\n",name2,sal2);
   fclose(ptr);
   getch();
   return 0;
}
