#include<stdio.h>

#define NONBLANK 'a'

int main(){
    int c, lastc;

    lastc = NONBLANK;
     /* we read the "text stream"
     *
     * when we encounter a new line
     * we drop into the loop
     *
     * getchar and putchar operate on per character basis
     * so we can inspect each character while in the loop
     *
     * c holds the integer representation of the character
     *
     * putchar prints the char representaiton of the int
     */
    while ((c = getchar()) != EOF){
       /* if c is not a blank, or lastc was not a blank
        * print it to the screen * */
       if (c != ' ' || lastc != ' ')
           putchar(c);
       lastc = c;
    }
    return 0;
}
