#include<stdio.h>
#include<string.h>
struct employee
{
   int code;
   float salary;
   char name[10];
};
int main()
{
   struct employee e1,e2,e3;
   printf("enter the values for code of e1\n:");
   scanf("%d",&e1.code);
   printf("enter the values for salary of e1\n:");
   scanf("%f",&e1.salary);
   printf("enter the values for name of e1\n:");
   scanf("%s",e1.code);

   printf("enter the values for code of e2\n:");
   scanf("%d",&e2.code);
   printf("enter the values for salary of e2\n:");
   scanf("%f",&e2.salary);
   printf("enter the values for name of e2\n:");
   scanf("%s",e2.code);

   printf("enter the values for code of e3\n:");
   scanf("%d",&e3.code);
   printf("enter the values for salary of e3\n:");
   scanf("%f",&e3.salary);
   printf("enter the values for name of e3\n:");
   scanf("%s",e3.code);
   return 0;
}

