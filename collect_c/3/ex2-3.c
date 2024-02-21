#include <stdio.h>
#include <string.h> // strlen
#include <math.h>   // pow
#include <stdlib.h> // exit

int _htoi(char[]);

int main()
{
    
    printf("The integer value of a hex string 0x19ef is %d\n", _htoi("0x19ef"));

    return 0; // return SUCCESS
}

int _htoi(char s[])
{
    int i, sum, len, d, subscript, end;

    i = 0;
    sum = 0;
    len = strlen(s);

    printf("The character string is %s\n", s);

    if (i < len && (i + 1) < len && s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
    {
        end = 2; // skip first two chars   
    }

    for (i = len - 1, subscript = 0; i >= end; i--, subscript++)
    {
        printf("The current character is %c\n", s[i]);

        if (s[i] >= '0' && s[i] <= '9') {
         
            d = s[i] - '0';
        
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            
            d = s[i] - 'A' + 10;

        } else if (s[i] >= 'a' && s[i] <= 'f') {
            
            d = s[i] - 'a' + 10;

        } else {
            
            printf("illegal hex character!\n");
            exit(1);
        }

        sum = sum + d * pow(16, subscript);
    }

    return sum;
}
