//#include <ctype.h>
#include <stdio.h>

/* strlen: return length of string s */
size_t myStrlen_v1(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++) {
        n++;
    }
    return n;
}

/* strlen: return length of string s */
size_t myStrlen_v2(char *s) {
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s;
}

int main() {
    size_t n1, n2;
    char c[] = "Martian.";
    n1 = myStrlen_v1(c);
    printf("The length of [%s] is : [%zu]\n", c, n1);

    n2 = myStrlen_v2("hello, world");
    printf("The length of [hello, world] is : [%zu]\n", n2);
}