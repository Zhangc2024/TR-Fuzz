#include<stdio.h>
#include<string.h>

/* Demonstrates the use of  strpbrk
 * char * strpbrk( const char *__s, const char *__accept )
 *
 * compare with any.c
 * */

int main(){
    char s1[] = "abcdefghi4jk4l";
    char s2[] = "34";
    char *ret;

    ret = strpbrk(s1, s2);
    if(ret)
        printf("first matching character %c\n", *ret);
    else
        printf("character not found");
    return 0;
}
