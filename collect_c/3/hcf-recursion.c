#include<stdio.h>
int hcf(int num1, int num2); 
int main()
{
 int num1,num2;
 printf("num1 - > ");
 scanf("%d",&num1);
 printf("num2 - > ");
 scanf("%d",&num2);
 printf("hcf is - > %d",hcf(num1, num2));
 return 0;
}

int hcf( int a, int b){
    if (b != 0 )
    {
        return hcf(b, a%b);
    }
    else 
    return a;
    
}