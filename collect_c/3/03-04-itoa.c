#include <stdio.h>
#define abs(x) ((x) < 0 ? -(x) : (x))

/* reverse: reverse string s      */
void reverse(char s[])
{
    int c,i,j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* itoa : convert n to characters in s - modified */

void itoa(int n, char s[]) {
    int i, sign;

    sign = n;
    i = 0;

    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

main(){
    char s[10];
    int n = -2147483648;
    itoa(n, s);
    printf("%s",s);
}
