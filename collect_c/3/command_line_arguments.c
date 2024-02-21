#include <stdio.h>

int main( int argc, char *argv[] )
{
    printf("Program name %s\n", argv[0]);
    printf("Number of argument: %d\n", argc);
    printf("Last argument supplied: %s\n", argv[argc-1]);

    if( argc == 2)
    {
        printf("The argument supplied is %s\n", argv[1]);
    }
    else if (argc > 2)
    {
        printf("Too many arguments supplied.\n");
    }
    else
    {
        printf("One argument expected.\n");
    }
    
}