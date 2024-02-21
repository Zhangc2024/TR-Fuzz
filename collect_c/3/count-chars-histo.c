# include <stdio.h>
# include <stdbool.h>

/* print histogram of frequencies of lowercase letters */

bool is_lower(char c){
    return c - 'a' < 26;
};


int main(){
    int c, i, j;
    int nlower[26];

    for (i = 0; i < 26; ++i)
        nlower[i] = 0;

    while((c = getchar()) != EOF)
        if (is_lower(c))
            ++nlower[c-'a'];

    printf("lower case histogram:\n");
    for (i = 0; i < 26; ++i){
        printf("%c: ", 'a' + i);
        for (j = 0; j < nlower[i]; ++j){
            printf("+");
        }
        printf("\n");
    }
    printf("\n");
}
