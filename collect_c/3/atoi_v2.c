# include <stdio.h>
# include <ctype.h>
/* atoi: convert s to integer; version 2 */
int myatoi(char s[]);

int main() {
    char str[] = "  -25a";
    int n = myatoi(str);
    printf("Convert string: [%s] to int: [%d]\n", str, n);
    return 0;
}

int myatoi(char s[]){
    int i, n, sign;
    // skip white space
    for(i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-')? -1 : 1;
    // skip sign if there is one
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}
