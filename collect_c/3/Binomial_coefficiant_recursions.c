#include<stdio.h>
int fact(n)
{
    if(n==0){
        return 1;
    }else{
        return n*fact(n-1);
    }
}
int main(){
    int n,r,a,b,c,res;
    scanf("%d%d",&n,&r);
    if(n<r){
        printf("invalid input");
    }else{
        a=fact(n);
        b=fact(n-r);
        c=fact(r);
        res=a/(b*c);
        printf("%d",res);
    }
    return 0;
}