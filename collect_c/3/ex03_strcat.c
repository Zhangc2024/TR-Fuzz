/**
 *
 * Exercise 5-3. Write a pointer version of the function strcat that we showed
 * in Chapter 2: strcat ( s, t) copies the string t to the end of s.
 *
 * Exercise 5-5. Write versions of the library functions strncpy, strncat,
 * and strncmp; which operate on at most the first n characters of their argument
 * strings. For example, strncpy ( s, t, n) copies at most n characters of t to s.
 * Full descriptions are in Appendix B.
 *
 **/

#include <stdio.h>
#include <string.h>


static void str_cat(char*, char*);
static void test(char*, char*, char*);


int main () {
    test("foo", "bar", "foobar");
    test("wu", "-tang", "wu-tang");
}

void test(char *s, char *t, char *exp){
    char buf[100] = {0};
    str_cat(buf, s);
    str_cat(buf, t);

    strcmp(exp, buf) == 0
      ? printf("PASS\n")
      : printf("FAIL \nexpected: %s, actual: %s\n", exp, buf);
}

void str_cat(char *s, char *t){
    while(*s++);
    s--;
    while((*s++ = *t++));
}
