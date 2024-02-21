#include<stdio.h>
int main(){
    float num;
    printf("enter the number : ");
    scanf("%f",&num);
    if (num<=0.0)
    {
        if (num==0)
        {
            printf("You have entered zero.");
        }
        else 
        printf("You have entered a negitive number.");
    }

    else 
    printf("You have entered a Positive number");
    return 0;
}