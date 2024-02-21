#include<stdio.h>
int main(){
    int array[10];
    printf("enter elements of array");
    for(int i=0;i<=10;i++){
        scanf("%d",&array[i]);
    }
    for(int i=0;i<=10;i++){
        printf("array[%d] : %d \n",i,array[i]);
    }
    return 0;
}