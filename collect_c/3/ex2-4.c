#include <stdio.h>

/* Exercise 2-4. squeeze(s1, s2) that deletes each character in s1 that
 * matches any character in the string s2.
 */

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "xyzarunsds";
    char s2[] = "arun";

    squeeze(s1, s2);

    printf("The modified s1[] is %s\n", s1);

    return 0; //return SUCCESS
}


void squeeze(char s1[], char s2[])
{

    int i, j, index, found;
    char s, c;

    index = found = 0;
    
    for (i = 0; s1[i] != '\0'; i++)
    {
        found = 0;

        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j]) {

                found = 1;

                break;
            }
        }
        
        if (!found)
        {
            s1[index++] = s1[i];
        }
    }
    
    s1[index] = '\0';
}

