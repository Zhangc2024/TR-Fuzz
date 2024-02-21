#include <stdio.h>

int main()
{
    int a, b, c;
    printf("enter value of a,b and c");
    scanf("%d %d %d", &a, &b, &c);
    printf("value of a,b and c is: %d, %d and %d\n", a, b, c);
    if (a > b && a > c)
    
       printf("value of a(%d) is greater than b(%d) and c(%d\n", a, b, c);
    
    else if (b > a && b>c)
    
       printf("value of b(%d) is greater than a(%d) and c(%d)\n", b, a, c);
    
    else
        printf("c(%d) is greater than a(%d) and b(%d\n",c,a,b);
    return 0;
}