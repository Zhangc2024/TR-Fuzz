#include <stdio.h>
int main()
{
    float son=13.12;
    float *fson=&son;
    printf("son=%.f\n", *fson);
    return 0;
}