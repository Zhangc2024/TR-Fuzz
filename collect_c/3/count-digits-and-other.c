# include <stdio.h>
# include <stdbool.h>

/* count digits, white space, others */

bool is_whitespace(char c);

bool is_digit(char c);

int main(){
    int c, i, nwhite, nother;
    int ndigit[10];

    nwhite = nother = 0;

    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while((c = getchar()) != EOF)
        if (is_digit(c))
            ++ndigit[c-'0'];
        else if (is_whitespace(c))
            ++nwhite;
        else
            ++nother;

    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}

bool is_whitespace(char c) { return c == ' ' || c == '\n' || c == '\t'; };

bool is_digit(char c) { return c >= '0' && c <= '9'; };
