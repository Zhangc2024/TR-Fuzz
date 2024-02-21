#include <stdio.h>
void swap(int *a, int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
void kiritish(int *a, int *b)
{
    scanf("%i%i", a,b);
}
int main()
{
    int son1, son2;
    printf("Ikkita sonni kiriting: ");
    kiritish(&son1,&son2);
    swap(&son1, &son2);
    printf("son1=%i\tson2=%i\n",son1, son2);
    return 0;
}