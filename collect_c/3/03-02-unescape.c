#include <stdio.h>

/* unescape: covert escape sequences into real characters */
/*           while copying the string t to s              */

void unescape(char s[], char t[]){
    int i,j;

    for (i = j = 0; t[i] != '\0'; i++)
        if (t[i] != '\\')
            s[j++] = t[i];
        else
            switch (t[++i]){
            case 'n':
                s[j++] = '\n';
                break;
            case 't':
                s[j++] = '\t';
                break;
            default:
                s[j++] = '\\';
                s[j++] = t[i];
                break;
            }
    s[j] = '\0';
}


main(){
    char t[15] = "hello\\n\\tworld\0";
    char s[15];

    unescape(s, t);

    printf("%s\n\n",t);
    printf("%s",s);
}
