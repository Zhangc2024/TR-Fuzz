#include<stdio.h>
int product(int a,int b){
    if(a<b){
        return product(b,a);
    }
    else if(b!=0){
        return (a+product(a,b-1));
    }
    else{
        return 0;
    }
}
int main(){
    int a=2,b=5,result;
    result=product(a,b);
    printf("product:%d",result);
    return 0;
}