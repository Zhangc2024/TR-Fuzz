//
// Exercise 2-3. Write the function htoi (s), which converts a string of hexa-
// decimal digits (including an optional Ox or ox) into its equivalent integer value.
// The allowable digits are 0 through 9, a through f, and A through F.
//

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int htoi(char *hex_str);
void test(char *hex_str, int expected);

int main() {
    test("000", 0);
    test("11", 17);
    test("111", 273);
    test("FFF", 4095);
    test("fff", 4095);
    test("123", 291);
    test("321", 801);
    test("1a2B", 6699);
    printf("correct!");
}

int htoi(char *hex_str) {
    int i, c, digit, res = 0;
    for (i = 0; i < strlen(hex_str); i++) {
        c = (int) hex_str[i];
        if (c >= 48 && c <= 57) digit = c - 48; // 0-1
        else if (c >= 65 && c <= 70) digit = c - 55; // A-F
        else if (c >= 97 && c <= 102) digit = c - 87; // a-f
        else {
            printf("FATAL ERROR: character %c (value %d) in string %s is not a valid hex digit", c, c, hex_str);
            exit(1);
        }
        // printf("place %d: char: %d, digit: %d\n", i, c, digit);
        res = 16 * res + digit;
    }
    return res;
}

void test(char *hex_str, int expected) {
    printf("\nchecking %s...\n", hex_str);
    int result = htoi(hex_str);
    printf("...got %d\n", result);
    assert(result == expected);
}
