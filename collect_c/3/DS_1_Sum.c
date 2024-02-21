#include<stdio.h>
void sum(int n){
     int sum=0;
     for(int i=1;i<=n;i++){
         sum=sum+i;
     }
     printf("The sum is:%d\n",sum);
     printf("The count is:%d\n",n);
}

int main(){
    int n;
    printf("Ente the number\n ");
    scanf("%d",&n);
    sum(n);

    return 0;
}