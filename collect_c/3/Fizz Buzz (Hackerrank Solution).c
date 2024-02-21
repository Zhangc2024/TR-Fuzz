/*
Given a number n, for each integer i in the range
from 1 to n inclusive, print one value per line as
follows:
If i is a multiple of both 3 and 5, print FizzBuzz.
� If i is a multiple of 3(but not 5), print Fizz.
� If iis a multiple of 5(but not 3), print Buzz.
� If i is not a multiple of 3 or 5, print the value of i.

CONSTRAINTS:-  0<n<2*10^5
*/

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

void fizzBuzz(int n) 
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(i%3==0&&i%5==0)
        {
            printf("FizzBuzz");
        }
        else if(i%3==0&&i%5!=0)
        {
            printf("Fizz");
        }
        else if(i%5==0&&i%3!=0)
        {
            printf("Buzz");
        }
        else 
        {
            printf("%d",i);
        }
        printf("\n");
    }
}

int main()
{
    int n = parse_int(ltrim(rtrim(readline())));

    fizzBuzz(n);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
