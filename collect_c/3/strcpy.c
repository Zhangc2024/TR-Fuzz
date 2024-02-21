#include<stdio.h>
#include<stdlib.h>
#define MAXCHAR 20

void mystrcpy(char*, char*);

int main() {
    char *s = "nickson";
    char *t = NULL;
    // dynamically allocated memory using malloc()
    t = (char*) malloc(sizeof(char) * (MAXCHAR + 1));
    mystrcpy(s, t);
    return 0;
}

/* strcpy: copy t to s; array subscript version */
void mystrcpy(char *s, char *t) {
    int i = 0;
    while((s[i] = t[i]) != '\0')
        i++;
    printf("%s\n", t);
}
