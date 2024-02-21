/* Exercise 4-13 */

#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 1024

void reverse(char []); 
void recursiverev(char [], int, int); 


int main()
{
    char s1[MAX_STR_LEN] = "Hello world!";
    printf("%s\t reverse: ", s1); 
    reverse(s1);
    printf("%s\n", s1); 

    char s2[MAX_STR_LEN] = "";                /* emptry string */
    printf("%s\t reverse: ", s2); 
    reverse(s2);
    printf("%s\n", s2); 

    char s3[MAX_STR_LEN] = "abcde";           
    printf("%s\t reverse: ", s3); 
    reverse(s3);
    printf("%s\n", s3); 
}

/* reverse: reverse the string s character by character */
void reverse(char s[])
{
    recursiverev(s, 0, strlen(s) - 1); 
}

/* recursiverev: reverse the substring from the i+1 th char
   to the jth char. Note that it is required that i <= j. 
*/
void recursiverev(char s[], int i, int j)
{
    if (i < j) {
	 char c = s[i]; 
	 s[i] = s[j]; 
	 s[j] = c;

	 recursiverev(s, i + 1, j - 1); 
    }
}
