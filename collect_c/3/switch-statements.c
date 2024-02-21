/*
    Switch Statements

    Similar to the if statement, a switch statement is a conditional statement.
    It accepts an expression (or variable, etc), and runs through a list of cases to compare to
    based on the result of the expression.

    If there is a 'break;' after a case, the switch stops there. If there isn't, it will "fall through",
    executing what's in each case, until it hits a 'break;' statement. (See second switch statement for an example.)

    There is also the 'default' statement. If no case is hit, the default will be executed.
*/

#include <stdio.h>

int main(void)
{
    int happy = 1;
    int birthday = 0;

    switch (happy) {
        case 0:
            printf("Why aren't you happy?\n");
            break;
        case 1:
            printf("Why are you happy? :)\n");
            break;
        default:
            printf("What will help you be happy?\n");
    }

    printf("\n\n\nIs today your birthday?\n");

    switch (birthday) {
        case 0:
            printf("Ah, sad. When is it?\n");
        case 1:
            printf("Happy birthday!\n");
        case 2:
            printf("What do you mean by two?\n");
            break;
        default:
            printf("I don't recognize that number...\n");
    }

    return 0;
}