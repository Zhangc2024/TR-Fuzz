#include <stdio.h>

/* Exercise 2-5. any(s1, s2) - the function returns the first location in the string s1
 * where any character from the string s2 occurs or -1 if s1 contains no characters from s2.
 */

int any(char s1[], char s2[]);

int main()
{

    printf("The return value of any(\"asads\", \"ds\") is %d\n", any("asads", "ds"));
    
    printf("The return value of any(\"asads\", \"xyz\") is %d\n", any("asads", "xyz"));

    return 0; //return SUCCESS
}

int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s2[j] == s1[i]) {
            
                return i;
            }
        }
    }

    return -1;
}
