/**
 *
 * Exercise 5-4. Write the function strend ( s, t), which returns 1
 * if the stringt occurs at the end of the string s, and zero otherwise.
 *
 **/

#include <stdio.h>

static int str_end(char*, char*);
static void test(char*, char*, int);

int main () {
    test("food", "od", 1);
    test("foods", "od", 0);
}

void test(char *s, char *t, int exp){
    int res = str_end(s, t);
    res == exp
    ? printf("PASS\n")
    : printf("FAIL \nexpected: %d, actual: %d\n", exp, res);
}

int str_end(char *s, char *t){
    // consume all non-matching chars from beginning of s
    while(*s++ != *t);
    // if we have consumed all of s, it does not contain t
    if (!*s)
        return 0;
    s--;
    // consume all matching chars
    while(*s++ == *t++);
    // if we have consumed all of s and t, t is at end of s
    return (!*(++s) && !*t);
}