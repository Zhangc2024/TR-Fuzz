#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();



int main()
{
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        printf("one");
    }
    if(n==2)
    {
        printf("two");
    }
    if(n==3)
    {
        printf("three");
    }
    if(n==4)
    {
        printf("four");
    }
    if(n==5)
    {
        printf("five");
    }
    if(n==6)
    {
        printf("six");
    }
    if(n==7)
    {
        printf("seven");
    }
    if(n==8)
    {
        printf("eight");
    }
    if(n==9)
    {
        printf("nine");
    }
    else if(n>9)
    {
        printf("Greater than 9");
    }
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

