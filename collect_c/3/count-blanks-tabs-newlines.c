#include<stdio.h>

int main(){
    int c, spaceCount, tabCount, newLineCount;
    spaceCount = tabCount = newLineCount = 0;

    while ((c = getchar()) != EOF){
        if (c == ' ')
            ++spaceCount;
        else if (c == '\t')
            ++tabCount;
        else if (c == '\n')
            ++newLineCount;
    }
    printf("spaces: %d\n", spaceCount);
    printf("tabs:  %d\n", tabCount);
    printf("newlines:  %d\n", newLineCount);
    return 0;
}
