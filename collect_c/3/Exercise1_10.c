#include <stdio.h>
/* '\t' is a character, while "\\t" is a string and need to display with printf
   Ctrl-v and Ctrl-h will generate '\b' on screen.*/
int main() 
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
}
