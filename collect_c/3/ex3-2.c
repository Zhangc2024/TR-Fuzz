#include <stdio.h>
#include <string.h>

/*
 * 
 * Exercise 3-2. escape(s, t). convert characters like newline and tab into visible
 * excape sequences like \n and \t as it copies string t to s.
 *
 */

void escape(char s[], char t[]);
void unescape(char s[], char t[]);


int main()
{
    char t[] = "\narun\nThe\tOne";
    char s[strlen(t) + 1];
    char us[strlen(t)+ 1];

    printf("The unescaped original string is %s\n", t);

    escape(s, t);

    printf("The escaped string is %s\n", s);

    unescape(us, s);

    printf("The unescaped string is %s\n", us);

    return 0; //return SUCCESS
}

void escape(char s[], char t[])
{
    int t_len = strlen(t);

    int i, j;

    for (i = 0, j = 0; i < t_len; i++)
    {
        
        switch(t[i]) {
        case '\n': 
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
    
    }

    s[j] = '\0';

}

void unescape(char s[], char t[])
{
    int t_len = strlen(t);

    int i, j, delimiter_found;

    delimiter_found = 0;

    for (i = 0, j = 0; i < t_len; i++)
    {
        
        switch(t[i]) {
        case '\\':

            delimiter_found = 1;
            break;
        case 'n':

            if (delimiter_found) {

                s[j++] = '\n';
                delimiter_found = 0;

            } else {

                s[j++] = 'n';

            }
            break;
        case 't':

            if (delimiter_found) {

                s[j++] = '\t';
                delimiter_found = 0;

            } else {

                s[j++] = 't';

            }
            break;

        default:

            if (delimiter_found) {
                s[j++] = '\\';
                delimiter_found = 0;

            } 

            s[j++] = t[i];
            break;
        }
    
    }

    s[j] = '\0';

}

