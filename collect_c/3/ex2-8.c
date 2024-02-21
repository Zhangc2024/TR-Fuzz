#include <stdio.h>
#include <limits.h>

/*
 * 
 * Exercise 2-8. rightrot(x, n) - returns the value of the integer x rotated to the right
 * by n bit positions
 *
 */

unsigned rightrot(unsigned x, int n);

int main()
{
    printf("The rightrot(4021, 2) is %d \n", rightrot(4021, 2));

    return 0; // return SUCCESS
}

unsigned rightrot(unsigned x, int n)
{
    //xxxxx001
    //000xxxxx
    
    //xxxxx001
    //00100000
    
    //idea from: http://users.powernet.co.uk/eton/kandr2/krx208.html
    size_t s = sizeof(x) * CHAR_BIT;

    return (x >> n) | (x << s - n);
}
