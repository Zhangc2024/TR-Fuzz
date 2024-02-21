#include <stdio.h>
#include <ctype.h>

/* atoi: convert s to integer; version 2 */
 int atoi(char s[]){
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)
    ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
 }

 main (){
    char s[6] = "-1234";
    printf("%s\n",s);
    printf("%d", atoi(s));
 }
