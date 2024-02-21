# include <stdio.h>
# define MAX 100
void expand(char s1[], char s2[]);

int main(){
    char s1[6] = {'a', '-', 'k', '0', '-', '3'};
    char s2[MAX];
    expand(s1, s2);
    for (int i = 0; s2[i] != '\0'; i++) {
        printf("%c ", s2[i]);
    }
    putchar('\n');
}

void expand(char s1[], char s2[]) {
    int i, j;
    for (i = j = 0; s1[i] != '\0'; i++) {
        if (s1[i] != '-') {
            s2[j++] = s1[i];
        } else {
            int inc = 1;
            while (inc < s1[i+1]-s1[i-1]) {
                s2[j++] = s1[i-1] + inc;
                inc++;
            }
        }
    }
    s2[j] = '\0';
}
