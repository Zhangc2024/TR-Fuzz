/**
 *
 * Exercise 5-5. Write versions of the library functions strncpy, strncat,
 * and strncmp; which operate on at most the first n characters of their argument
 * strings. For example, strncpy ( s, t, n) copies at most n characters of t to s.
 * Full descriptions are in Appendix B.
 *
 **/

#include <stdio.h>
#include <string.h>


static void str_cpy(char* s, char* t, int n);
static void test_cpy(char* s, char* t, int n , char* r);
static void str_ncat(char* s, char* t, int n);
static void test_ncat(char* s, char* t, int n, char *r);


int main () {
    static char s1[100], s2[100];

    test_cpy(s1, "foobar", 6, "foobar");
    test_cpy(s2, "foobar", 3, "foo");

    test_ncat("foo", "bar", 3, "foobar");
    test_ncat("foo", "bar", 1, "foob");
}

void test_cpy(char *s, char *t, int n, char *r){
    str_cpy(s, t, n);

    strcmp(r, s) == 0
      ? printf("PASS\n")
      : printf("FAIL \nexpected: %s, actual: %s\n", r, s);
}

void str_cpy(char *s, char *t, int n){
    int i = 0;
    while(i++ < n && (*s++ = *t++));
}

void test_ncat(char *s, char *t, int n, char *r){
    char b[100] = {0};
    strcpy(b, s);
    str_ncat(b, t, n);

    strcmp(r, b) == 0
       ? printf("PASS\n")
       : printf("FAIL \nexpected: %s, actual: %s\n", r, b);
}


static void str_ncat(char* s, char* t, int n) {
    int i = 0;
    while(*s++);
    s--;
    while(i++ < n && (*s++ = *t++));
}