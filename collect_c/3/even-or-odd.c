#include<stdio.h>
int main(){
    int a;
    printf("enter value of a :\n");
    scanf("%d",&a);
    if (a%2 == 0)
    {
        printf("the : %d : is a even value",a);
    }
    else {
        printf("the : %d : is a odd value",a);
    }
    
    
    return 0;
};