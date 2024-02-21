#include<stdio.h>

int main(){
    int a,b,temp;
    a = 5; b=7;
    printf("a & b before swapping : %d , %d\n",a,b);
    //swap function
    temp = a;
    a = b;
    b =  temp;
    printf("a & b after swapping : %d , %d\n",a,b);
    return 0;
};