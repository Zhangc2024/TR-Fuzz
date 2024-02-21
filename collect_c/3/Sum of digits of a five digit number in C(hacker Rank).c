#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n;
    int sum,i;
    scanf("%d", &n);
    sum=0;
    for(i=n;i!=0;i=i/10)
    {
        sum+=(i%10);
    }
    printf("%d",sum);
    return 0;
}

