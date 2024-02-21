#include<stdio.h>

typedef struct employee{
    int number;
    char name[20];
    float salary;
}emp;
int main(){
    emp e1={101,"karthik shetty",10000};
    emp e2={102,"keerthan",10000};
    
    printf("Employee number:%d\n",e1.number);
    printf("Employee name:%s\n",e1.name);
    printf("Employee salary:%f\n",e1.salary);
    printf("************************************\n");
    printf("Employee number:%d\n",e2.number);
    printf("Employee name:%s\n",e2.name);
    printf("Employee salary:%f\n",e2.salary);
    return 0;
}