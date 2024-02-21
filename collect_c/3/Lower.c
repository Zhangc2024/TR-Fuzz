/* Exercise 2-10 */ 

/* lower: converts upper case letters to lower case
   with a conditional expression. 
*/

#include <stdio.h> 

char lower(char c); 

int main()
{
    printf("%c\n", lower('A')); // a
    printf("%c\n", lower('Z')); // z
    printf("%c\n", lower('X')); // x
    printf("%c\n", lower('%')); // %
    printf("%c\n", lower(' ')); // ' '
    printf("%c\n", lower('!')); // !
}

/* lower(c); converts upper case letters to lower case, 
   return c itself if c is not upper case. 
*/ 
char lower(char c)
{
    return (c >= 'A' && c <= 'Z')? c - 'A' + 'a' : c; 
}
