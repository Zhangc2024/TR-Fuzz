#include<stdio.h>
struct emp
{
   int no;
   char name[20];
   float salary;
};
int main()
{
   struct emp e={100,"karthik",50000};
   clrscr();
   printf("__________________________________________________________\n");
   printf("employee details:\n");
   printf("__________________________________________________________\n");
   printf("emp_no:%d\temp_name:%s\temp_salary:%.0f\n",e.no,e.name,e.salary); \
   printf("__________________________________________________________\n");
   getch();
   return 0;
}


