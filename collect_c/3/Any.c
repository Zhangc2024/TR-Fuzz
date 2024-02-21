/* Exercise 2-5 */

/* Function any(s1, s2), which returns the first location
   in the string s1 where any character from the string s2 occurs, 
   or -1 if s1 contains no characters from s2. 
*/

#include <stdio.h>
#include <limits.h>

int any(char s1[], char s2[]); 

int main()
{
    char s1[128] = "abcdefg";
    char s2[4]   = "a"; 
    int r1 = any(s1, s2); 
    printf("test 1: %d\n", r1); // should print 0

    char s3[4] = "abc";
    char s4[128] = "!@#$%^&xxxxvvvv*c"; 
    int r2 = any(s3, s4); 
    printf("test 1: %d\n", r2); // should print 2

    char s5[128] = "";
    char s6[128] = "0x5689AXH"; 
    int r3 = any(s5, s6); 
    printf("test 1: %d\n", r3); // should print -1
}

/* any(s1, s2): returns the first location in s1 where any 
   character from the string s2 occurs, or -1 if s1 contains no 
   characters from s2. 
*/
int any(char s1[], char s2[])
{
    /* loop through s2 to find the chars that show up
       and fill an array of indicators. 
     */
    int char_flag[CHAR_MAX];
    for (int i = 0; i < CHAR_MAX; ++i)
	char_flag[i] = 0; 

    for (int i = 0; s2[i] != '\0'; ++i) {
	if (char_flag[(int)s2[i]] == 0)
	    ++char_flag[(int)s2[i]];
    }

    /* go through s1 to find the first char */
    for (int i = 0; s1[i] != '\0'; ++i) {
	if (char_flag[(int)s1[i]])
	    return i; 
    }

    return -1;
}
