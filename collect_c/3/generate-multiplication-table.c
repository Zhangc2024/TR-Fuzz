#include<stdio.h>
int main(){
    int tbvalue=1,num,i;
    printf("enter value of number : ");
    scanf("%d",&num);
    printf("Multiplication table of %d is : \n",num);
    for(i=1;i<=10;i++)
    {
        tbvalue = num*i;
        printf("%d\n",tbvalue);
    }
    
    return 0;
}