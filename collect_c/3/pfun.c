/* c-examples by A.Shtanyuk */
/* pfun.c - pointers to function */

#include<stdio.h>

void test1(int a)
{
    printf("a1 = %d\n", a);
}

void test2(int a)
{
    printf("a2 = %d\n", a);
}

void test3(int a)
{
    printf("a3 = %d\n", a);
}

int main()
{
    void (*fpa[3])();

    fpa[0] = test1;
    fpa[1] = test2;
    fpa[2] = test3;

    (*fpa[0])(1);
    (*fpa[1])(2);
    (*fpa[2])(3);

    fpa[0](11);
    fpa[1](12);
    fpa[2](13);
}