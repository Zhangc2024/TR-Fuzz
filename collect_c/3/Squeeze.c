/* Exercise 2-4 */

/* sequeeze(s1, s2): A function that deletes each
   character in s1 that matches any character in the 
   string s2. 
*/

#include <stdio.h>
#include <limits.h>

void squeeze(char s1[], char s2[]); 

int main()
{
    char s1[128] = "abcdefabcdef";
    char s2[128] = "cf"; 
    squeeze(s1, s2); 
    printf("%s\n", s1); 

    char s3[128] = "cf";
    char s4[128] = "abcdefabcdef"; 
    squeeze(s3, s4); 
    printf("%s\n", s3); 

    char s5[128] = "123456\t!@#$%^";
    char s6[128] = "&*()123$%\t^"; 
    squeeze(s5, s6); 
    printf("%s\n", s5); 
}

/* squeeze(s1, s2): delete any chars in s2 that are
   in s1. 
*/
void squeeze(char s1[], char s2[])
{
    /* loop through all of s2 to find all the
       chars that show up and fill an array of 
       indicators. 
     */
    /* declare and initialize the indicator array. */
    int char_flag[CHAR_MAX];
    for (int i = 0; i < CHAR_MAX; ++i)
	char_flag[i] = 0; 

    int i = 0; 
    while (s2[i] != '\0') {
	if (char_flag[(int)s2[i]] == 0)
	    ++char_flag[(int)s2[i]]; 
	i++; 
    }

    /* go through s1 to delete the chars */
    int j; 
    for (j = i = 0; s1[i] != '\0'; i++) {
	if (char_flag[(int)s1[i]] == 0)
	    s1[j++] = s1[i];
    }
    s1[j] = '\0'; 
}
