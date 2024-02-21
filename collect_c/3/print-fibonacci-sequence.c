#include <stdio.h>
int main(){
    int i,n, term1 =0,term2 =1, next_term;
    printf("enter the value of terms : ");
    scanf("%d",&n);
    next_term = term1 + term2;
    printf("The febonacci series is : %d %d ",term1,term2);
    for (i=3;i<=n;i++){
        printf(" %d ",next_term);
        term1 = term2;
        term2 = next_term;
        next_term = term1 + term2;
    }
    return 0;
}