# include <stdio.h>
/* atoi: convert s to integer */
int myatoi(char s[]);
int main() {
    char str[] = "25";
    int n = myatoi(str);
    printf("The conversion number is %d\n", n);
}

int myatoi(char s[]) {
    int i, n;
    n = 0;
    for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}
