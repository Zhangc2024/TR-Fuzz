//
// Exercise 2-5. Write the function any (s1, s2), which returns the first location
// in the string s 1 where any character from the string s2 occurs, or -1 if s 1
// contains no characters from s2. (The standard library function strpbrk does
// the same job but returns a pointer to the location.)
//

#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int any(const char *s1, const char *s2);
void test(char *s1, char *s2, int expected);

int main() {
    test("abc", "foo", -1);
    test("abc", "abc", 0);
    test("abc", "bcd", 1);
    test("abc", "cd", 2);
    test("aabc", "bcd", 2);
    test("abbc", "bcd", 1);
    test("babc", "abcd", 0);
}

// increment notation allows us to write this:
int any(const char *s1, const char *s2) {
    int r=-1;
    for(int i=-1; s2[++i] != '\0';)
        for(int j=-1; s1[++j] != '\0';)
            if(s1[j] == s2[i] && (j < r || r == -1))
                r = j;
    return r;
}

// instead of writing this:
//
//int any(const char *s1, const char *s2) {
//    int r=-1
//    for(i = 0; s2[i] != '\0'; i++)
//        for(j = 0; s1[j] != '\0'; j++)
//            if(s1[j] == s2[i] && (j < r || r == -1))
//                r = j;
//    return r;
//}

void test(char *s1, char *s2, int expected) {
    printf("\ntesting s1='%s', s2='%s'...\n", s1, s2);
    int actual = any(s1, s2);
    printf("  expected: %d, actual: %d\n", expected, actual);
    printf("  --> %s\n", actual == expected ? "PASS" : "FAIL");
}

