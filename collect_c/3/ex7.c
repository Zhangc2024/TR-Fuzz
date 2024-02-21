#include <stdio.h>

/* Ex 1-8. Program to count blanks, tabs, and newlines */

int main()
{
    int c;
    long blank_count = 0, tab_count = 0, newline_count = 0;

    while((c = getchar()) != EOF) {
        
        if (c == ' ') {
            
            blank_count++;

        } else if (c == '\t') {
            
            tab_count++;

        } else if (c == '\n') {
            
            newline_count++;

        } else {
            // ignore other characters  
        }
    }

    printf("No of blanks : %ld\n", blank_count++);
    printf("No of tabs : %ld\n", tab_count++);
    printf("No of newlines : %ld\n", newline_count++);

    return 0;
}
