#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Tower(int n,char s,char t,char d){
    if(n==0){
       return;
    }
    Tower(n-1,s,d,t);
    printf("\nMove disk %d from %c to %c",n,s,d);
    Tower(n-1,t,s,d);
}

int main(){
    int n;
    printf("enter the number of disks\n");
    scanf("%d",&n);
    Tower(n,'A','B','C');
    printf("\nTotal number of moves=%0.1f",pow(2,n)-1);
    return 0;
}