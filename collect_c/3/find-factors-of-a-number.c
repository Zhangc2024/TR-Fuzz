#include<stdio.h>

int main(){
 int num;
 printf("enter value of number -> ");
 scanf("%d",&num);
 printf("Factors of %d are : ");
 for (int i=1;i<=num;++i){
    if (num%i == 0)
    {
        printf("%d ",i);
    }
    
 }
 return 0;
}