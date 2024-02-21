#include <stdio.h>

/* 
 * 
 * expand : expand(s1, s2) that expands shorthand notations like a-z in the string
 * s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case
 * and digits and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a 
 * leading or trailing - is taken literally
 *
 */

void expand(char s1[], char s2[]);

int main()
{
    char s1[] = "a-z";
    char s2[30];
    
    expand(s1, s2);

    printf("The expanded %s is %s\n", s1, s2);


    return 0; //return SUCCESS
}

void expand(char s1[], char s2[])
{
    
    char c;
    int i, j;

    i = j = 0;

    while ((c = s1[i++]) != '\0') /* fetch a char from s1[] */
    { 
        
        if (s1[i] == '-' && s1[i + 1] >= c) {

            i++;

            while (c < s1[i]) 
            {
                s2[j++] = c++;
            
            }

        } else {

            s2[j++] = c;
        }
    }

    s2[j] = '\0';
}
