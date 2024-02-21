/* Exercise 4-1 */

/* Write a function strrindex(s, t), which returns the position 
   of the rightmost occurrence of t in s, or -1 if there is none. 
*/

#include <stdio.h>

int strrindex(char s[], char t[]);

int main()
{
    printf("%d\n", strrindex("eeeeee", "e"));  // 5
    printf("%d\n", strrindex("eeeeee", "a"));  // -1
    printf("%d\n", strrindex("abcbcbcbcba", "bc"));  // 7
    printf("%d\n", strrindex("abcdefg", "ghi"));  // -1
    printf("%d\n", strrindex("5689122", "5"));  // 0
}

/* strrindex(s, t): returns the position of the rightmost occurrence 
   of t in s, or -1 if there is none.
*/
int strrindex(char s[], char t[])
{
    int i, j, k; 
    int r = -1; 

    for (i = 0; s[i] != '\0'; i++) {
	for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) 
	    ;
	if (k > 0 && t[k] == '\0')
	    r = i;  
    }

    return r; 
} 


