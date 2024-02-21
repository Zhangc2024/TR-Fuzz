#include <stdio.h>

/* itob: convert n to characters in s - base b */
void itob(int n, char s[], int b){
    int i, j, sign;
    //void reverse(char s[]);

    if ((sign = n ) < 0)
        n = -n;
    i = 0;
    do {
        j = n % b;
        s[i++] = (j <= 9) ? j+'0' : j+'a'-10;
    } while ((n /= b) > 0);

    if ( sign < 0 )
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

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

main(){
    int n, b;
    char s[20];

    n = 1000;
    b = 16;
    itob(n, s, b);
    printf("%s", s);
}
