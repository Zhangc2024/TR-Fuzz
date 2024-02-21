# include <stdio.h>
int any(char s1[], char s2[]);

int main() {
    char s1[] = "Hello, world!";
    char s2[] = "!wo";
    int loc = any(s1, s2);
    printf("s1: %s, s2: %s\n", s1, s2);
    printf("First occurrence of char from s2 in s1: %d\n", loc);
}

/* any: return first location in s1 where any char from s2 occurs */
int any(char s1[], char s2[]){
    for(int i = 0; s1[i] != '\0'; i++){
        for(int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;
}
