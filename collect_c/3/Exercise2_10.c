# include <stdio.h>
/* lower: convert c to lower case; ASCII only */
int lower(int c);
int main() {
    int c;
    while((c = getchar()) != EOF){
        if(c != '\n'){
            char letter = lower(c);
            printf("%c to lower case: %c\n", c, letter);
        }
    }
    return 0;
}

int lower(int c){
    return (c >= 'A' && c<= 'Z') ? (c + 'a' - 'A') : c;
}
