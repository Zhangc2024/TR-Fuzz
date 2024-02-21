#include <stdio.h>
int main(){
    int basenum,powervalue;
    printf("enter the base number value : ");
    scanf("%d",&basenum);
    printf("enter the number power value : ");
    scanf("%d",&powervalue);
    int result = 1.0;
    printf("You are calculating %d with power %d ",basenum,powervalue);
    while(powervalue!=0){
        result *= basenum;
        --powervalue;
    }
    printf("the final output is : %d",result);
    return 0;
}