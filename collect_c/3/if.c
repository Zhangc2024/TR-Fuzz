/*include the libraries*/
#include <stdio.h>

/*define the main function*/
int main()
{
    /*local variable definition*/
    int a = 100;
    int b = 200;

    /*check the boolean condition*/
    if(a == 100)
    {
        /*if condition is true then check the following*/
        if(b == 200)
        {
            /*if condition is true then print the following*/
            printf("Value of a is 100 and b is 200\n");
        }
    }

    /*print the output*/
    printf("Exact value of a is : %d\n", a);
    printf("Exact value of b is : %d\n", b);

    return 0;
}