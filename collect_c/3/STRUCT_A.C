#include<stdio.h>
typedef struct employee{
   int no;
   char name[20];
   int salary;
}emp;
int main()
{
   emp e[3];
   int i;
 
   for(i=0;i<3;i++)
   {
	 printf("enter the emp%d no:\n",i+1);
	 scanf("%d",&e[i].no);
	 printf("enter the emp%d name:\n",i+1);
	 scanf("%s",e[i].name);
	 printf("enter the emp%d salary:\n",i+1);
	 scanf("%d",&e[i].salary);
   }
   printf("__________________________________________________________\n");
   printf("employee details:\n");
   printf("__________________________________________________________\n");
   for(i=0;i<3;i++)
   {
	 printf("emp_no:%d\temp_name:%s\temp_salary:%d\n",e[i].no,e[i].name,e[i].salary);
	 printf("____________________________________________________________\n");
   }
   printf("__________________________________________________________\n");
  
   return 0;
}

