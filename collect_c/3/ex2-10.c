#include <stdio.h>

/* Exercise 2-10. rewrite lower using conditional expression instead of if-else */

int lower(int c);

int main()
{
    printf("The lower of D is %c \n", lower('D'));

    return 0; //return SUCCESS
}

int lower(int c)
{
    
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
    
}
