#include<stdio.h>

int main(){
    int i,n,count,j;
    printf("enter the number\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        count=0;
        for(j=1;j<=n;j++){
            if(i%j==0)
                count++;
            
        }  
           if(count==2)
            printf("%d ",i);
    }
    return 0;
}