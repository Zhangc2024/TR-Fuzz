#include<stdio.h>
int largest(int a[],int n){
    int large=0;
    for(int i=0;i<n;i++){
        if(a[i]>large){
            large=a[i];
        }
    }
    return large;
}

int main(){
    int a[20],n,large;
    printf("enter the number\n");
    scanf("%d",&n);
    printf("enter the elements\n");      
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    large=largest(a,n);
         
   printf("the largest number is:%d\n",large);
    return 0;
}