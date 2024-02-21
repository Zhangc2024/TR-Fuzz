#include<stdio.h>
int main(){
    int lower,upper;
    printf("enter the value of lower limit : ");
    scanf("%d",&lower);
    printf("enter the value of upper limit : ");
    scanf("%d",&upper);
    printf("You want to print prime numbers in \nRange %d and %d are : ",lower,upper);
    int flag = 0;
    for (int i=lower;i<upper;i++)
    {
        flag = 0;
        for(int j=2;j<=i/2;++j){
            if (i%j==0)
            {
                flag=1;
                break;
            }
            
        }
        if(flag==0){
            printf(" %d",i);
        }

    }
    return 0;
}