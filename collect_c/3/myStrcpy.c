/* strcpy: copy t to s; array subscript version */
#include <stdio.h>
#include <string.h>

void myStrcpy_v1(char *s, char *t) {
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0') {
        i++;
    }
}

void myStrcpy_v2(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

void myStrcpy_v3 (char *s, char *t) {
    while ((*(s++) = *(t++)) != '\0')
        ;
}

void myStrcpy_v4(char *s, char *t) {
    while (*(s++) = *(t++)) // ends when expression is 0.
        ;
}

int main() {
    char str[20] = "C programming";
    char str1[20];
    char str2[20];
    char str3[20];
    char str4[20];

    // copying str1 to str2
    myStrcpy_v1(str1, str);
    myStrcpy_v2(str2, str);
    myStrcpy_v3(str3, str);
    myStrcpy_v4(str4, str);

    printf("After copying str, str1: %s\n", str1);
    printf("After copying str, str2: %s\n", str2);
    printf("After copying str, str3: %s\n", str3);
    printf("After copying str, str4: %s\n", str4);
    return 0;
}