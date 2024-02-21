/*
    Unions

    C has something similar to structs called 'unions'. Unions have one main difference...
    Unions share the same memory space for all their members. So, a union can only have one 'value'
    at a time- which is one of the fields.

    Below, we have an example union called 'trash'. The trash can only hold coffee cups, apple cores,
    or orangeJuice, and only one at a time.
*/
#include <stdio.h>

union trash {
    int coffeeCups;
    int appleCores;
    float orangeJuice;
};

/* all this does is print the 3 fields from a 'union trash' union */
void printTrash(union trash *someonesTrash) {
    printf("%d %d %.2f\n", someonesTrash->coffeeCups, someonesTrash->appleCores, someonesTrash->orangeJuice);
}

int main(void)
{
    union trash myTrash;            /* we declare the myTrash instance of union trash */

    printTrash(&myTrash);           /* print myTrash */
    
    myTrash.coffeeCups = 5;         /* set coffee cups to 5 */

    printTrash(&myTrash);           /* notice in the output... all ints in the union
                                       have changed to 5, because it's the SAME location in memory.
                                       The float field is printing incorrectly due to my format specifier
                                       in the printTrash() function, and probably because the computer
                                       is trying to read the same piece of memory as a float, when it's
                                       really an int. */

    myTrash.appleCores = 10;
    myTrash.orangeJuice = 50.8;

    printTrash(&myTrash);

    return 0;
}