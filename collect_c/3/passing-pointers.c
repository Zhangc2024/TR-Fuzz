/*
    Passing Pointers

    Well... we wanna use pointers right? Here's a good way to do it.
    We can pass the reference to a value, rather than copying it on to the stack for the function!
    This will be helpful, especially when we want to pass things like arrays.
*/

#include <stdio.h>

void bobbyJoinsTheParty(int *p);

int main(void)
{
    int steak = 10; /* we have 10 steaks */

    printf("How many steaks do we have? %d\n", steak);

    printf("Bobby joins the party!\n");
    bobbyJoinsTheParty(&steak); /* will add 10 to the value of the variable at the location passed */

    printf("How many steaks do we have now? %d\n", steak);

    return 0;
}

/*
    This function takes an int pointer as its parameter.
    Remember- all this means is that it takes a memory address to an int value.

    This is passing a variable "by reference", because we're literally passing
    the reference (to the address) of the variable.

    We'll add 10 to whatever was passed in, cuz when Bobby joins the party,
    he increases everything by 10!
*/
void bobbyJoinsTheParty(int *p)
{
    *p += 10;
}