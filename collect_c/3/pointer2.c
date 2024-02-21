#include <stdio.h>
int main()
{
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    int *p=A; // p=&A[0]
    printf("int seriyaning 1-chi elementi %i\n", *p);
    p++; // A[0+1]=A[1]
    printf("int seriyaning 2-chi elementi %i\n", *p);
    p+=5; // A[1+5]=A[6]
    printf("int seriyaning 7-chi elementi %i\n", *p);
    p--;
    printf("int seriyaning 6-chi elementi %i\n", *p);
    p-=5;
    printf("int seriyaning 1-chi elementi %i\n", *p);
    p--;
    printf("int seriyaning 0-chi elementi %i\n", *p);
    char text[30]="Salom";
    char *pp=text;
    printf("char seriyaning 1-chi elementi %c\n", *pp);
    pp++;
    *pp='b';
    printf("char seriyaning 2-chi elementi %c\n", *pp);
    puts(text);
    return 0;
}