#include <stdio.h>
#include <string.h>
#define MAX 100

// This is from the answer book
void reverse(char [], int, int);

int main() {
    char str[MAX] = "hello, world";
    printf("Original string: [%s]\n", str);
    int left = 0, right = strlen(str) - 1;
    reverse(str, left, right);
    printf("After reversing: [%s]\n", str);
    return 0;
}

void reverse(char s[], int left, int right) {
    if (left >= right) {
        return;
    }
    char tmp = s[left];
    s[left] = s[right];
    s[right] = tmp;
    reverse(s, left + 1, right - 1);
}
