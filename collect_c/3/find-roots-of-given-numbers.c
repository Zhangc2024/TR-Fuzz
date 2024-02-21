#include<stdio.h>
#include <math.h>
int main(){
    double a,b,c,discriminant,root1,root2,rp,ip;
    printf("Enter the value of a,b and c");
    scanf("%lf %lf %lf",&a,&b,&c);
    printf("values are a :%lf , b :%lf and c : %lf ",a,b,c);
    discriminant = b*b -4*a*c;
    if (discriminant > 0)
    {
        root1 = (-b + sqrt(discriminant))/ (2*a);
        root2 = (-b - sqrt(discriminant))/ (2*a);
        printf("Root1 and Root2 are %lf and %lf",root1,root2);
    }
    else if (discriminant == 0)
    {
        root1 = root2 = -b / (2*a);
        printf("Root1 and Root2 are %lf and %lf",root1,root2);
    }
    else
    {
        rp = -b/ (2*a);
        ip = sqrt(-discriminant)/ (2*a);
        printf("Root1 and Root2 are %.2lf + %.2lfi and %.2lf - %.2lfi",rp,ip,rp,ip);
    }
    return 0;
}