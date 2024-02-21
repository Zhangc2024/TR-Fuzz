#include <stdio.h>

/* 1.10 External variables and scope */

#define MAXLINE 1000 //maximum input line size

int max; //max length seen so far
char line[MAXLINE]; // current input line
char longest[MAXLINE]; //longest line saved here

int _getline(void);
void _copy(void);

/* print longest input line; specialized version */


int main()
{   
    int len;

    max = 0;
    
    while ((len = _getline()) > 0)
    {
        if (len > max) {

            max = len;
            _copy();
        }
    }

    if (max > 0) {
        
        printf("The longest line is %s", longest);
    }

    return 0;
}

// _getline: specialized version
int _getline(void)
{
    int c, i;
   
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}

// _copy: specialied version 
void _copy(void)
{
    int i;

    i = 0;

    while ((longest[i] = line[i]) != '\0')
    {
        i++;
    }
}
