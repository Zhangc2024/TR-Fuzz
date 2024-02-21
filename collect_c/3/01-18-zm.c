/* delete all the blank space and tab in the end*/

#include <stdio.h>
#define MAXLENGTH 1000

int cutblank(char line[], int len);
void printl(char line[]);

main(){
    int i, c ;
    char line[MAXLENGTH];

    i=0;
    while ((c = getchar()) != EOF ){
        if (c == '\n'){
            if (i == 0)
                ;//printf("got a blank line\n");
            else{
                i = cutblank(line,i);
                if (i > 0){
                    ++i;
                    line[i]='\n';
                    ++i;
                    line[i]='\0';
                    printl(line);
                    i = 0;
                }
            }
        }else{
            line[i] = c;
            ++i;
        }
    }
    if (i > 0){
        i = cutblank(line,i);
        ++i;
        line[i]='\0';
        printl(line);
        i = 0;
    }
}

void printl(char line[])
{
    int i;
    i = 0;
    while (line[i] != '\0'){
        putchar(line[i]);
        ++i;
    }
}

int cutblank(char s[],int len)
{
    int c;
    --len;

    while (len >= 0 ){
        c = s[len];
        if ( c == ' ' || c == '\t'){
            //printf("got a space\n");
            if (len == 0)
                return 0;
            --len;
        } else {
            return len;
        }
    }
}
