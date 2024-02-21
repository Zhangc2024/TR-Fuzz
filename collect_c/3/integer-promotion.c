/*
    Integer Promotion

    Compile this file. You'll notice that we get:
    -1 > 1
    -1 < 1
    for our result! Except... usually... -1 > 1 is NOT true! So, what's going on?

    It's due to "integer promotion". In the first if statement, the size for our signed short is increased to match
    the size of the unsigned int; however, it's never "converted" from signed to unsigned. The same happens when you cast a variable
    to a variable of a larger size. B/c it was a two's compliment negative number, the ones (in binary) are filled out to increase the size,
    but it's read as an unsigned int. Therefore, it's reading -1 as larger than 1, because the casted value is no longer read as a -1 by the computer.

    A good explanation: https://stackoverflow.com/questions/46073295/implicit-type-promotion-rules

    Thanks https://fabiensanglard.net/c/ for an example of integer promotion!
*/

#include <stdio.h>

int main(void)
{
    unsigned int   ui_one       =  1 ;
    signed   int   i_one        =  1 ;
    signed   short s_minus_one  = -1 ;
	
    if( s_minus_one > ui_one)
		printf("-1 > 1 \n");
	
    if( s_minus_one < i_one) 
		printf("-1 < 1 \n");

    return 0;
}