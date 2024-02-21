#include<stdio.h>

void getname(char *);

int main() {
    char *name = "nickson";
    getname(name);
    name = "kaigi";
    getname(name);
    return 0;
}

void getname(char *name){
    printf("%s\n", name);
}
