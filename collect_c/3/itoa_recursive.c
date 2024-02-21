/* Exercise 4-12 */

#include <stdio.h>
#include <limits.h>

#define MAX_STR_LEN 1024

void itoa(int n, char s[]); 

int main()
{
    char s[MAX_STR_LEN];
    int i; 

    i = 256;
    itoa(i, s); 
    printf("%d\t%s\n", i, s); 
    
    i = INT_MIN; 
    itoa(i, s); 
    printf("%d\t%s\n", i, s); 
}

/* itoarecur: converts the int n recursively */ 
int itoarecur(int n, char s[], int i);

/* itoa: conversts int n into a string and store it in s */
void itoa(int n, char s[])
{  
    int j = 0; 

    if (n > 0)
	n = -n; 
    else 
	s[j++] = '-'; 
    
    j = itoarecur(n, s, j); 
    s[j] = '\0'; 
}

/* itoarecur: convert n into a string and store it in s, 
   starting at index i. n has to be a negative integer, or 0.
*/
int itoarecur(int n, char s[], int i) 
{
    int j = i; 
    if (n / 10)
	j = itoarecur(n / 10, s, i); 
    s[j] = -(n % 10) + '0'; 
    return ++j; 
}
