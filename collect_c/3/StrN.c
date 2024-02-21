/* Exercise 5-5 */
/* strncpy strncat strncmp */

#include <stdio.h>

#define MAX_STR_LEN 256

char *strncpy(char *, const char *, size_t); 
char *strncat(char *, const char *, size_t); 
int strncmp(const char *, const char *, size_t); 

int main()
{
    printf("Hello world\n");
    char s1[MAX_STR_LEN]; 
    char t1[MAX_STR_LEN] = "!@#$% string to copy!"; 
    printf("%s\n", strncpy(s1, t1, MAX_STR_LEN)); 
    printf("%s\n", strncpy(s1, t1, 2)); 
    printf("%s\n", strncpy(s1, t1, 0));

    char s2[MAX_STR_LEN] = "Hello "; 
    char t2[MAX_STR_LEN] = "!@#$% string to copy!";
    printf("%s\n", strncat(s2, t2, MAX_STR_LEN / 2)); 
    printf("%s\n", strncat(s2, t2, 2)); 
    printf("%s\n", strncat(s2, t2, 0));

    char s3[MAX_STR_LEN] = "Helzo "; 
    char t3[MAX_STR_LEN] = "Heklo ";
    printf("%d\n", strncmp(s3, t3, MAX_STR_LEN)); 
    printf("%d\n", strncmp(s3, t3, 3)); 
    printf("%d\n", strncmp(s3, t3, 1));
    printf("%d\n", strncmp(s3, t3, 0));
}

/* strncpy: copy n characters from ct to s if possible. */
char *strncpy(char *s, const char *ct, size_t n)
{
    if (n == 0)
	return s; 

    char *str = s; 
    size_t idx = 0; 
    while ((*s++ = *ct++) && idx < n - 1) 
	idx++; 
 
    if (*ct)
	*s = '\0'; 
    
    return str; 
}

/* strncat: concatenate at most n characters from ct to s. */
char *strncat(char *s, const char *ct, size_t n)
{
    if (n == 0)
	return s; 

    char *str = s; 
    size_t idx = 0; 

    while (*s) /* seek the end of s */ 
	s++; 

    for ( ; (*s++ = *ct++) && idx < n - 1; idx++)
	; 

    return str; 
}

/* strncmp: compare at most n characers of string cs
   to string ct. return < 0 if cs < ct, 0 if cs==ct
   or > 0 if cs > ct
 */
int strncmp(const char *cs, const char *ct, size_t n)
{
    if (n == 0)
	return 0; /* comparing empty string with empty string gives equality */
    size_t i = 0; 
    for ( ; *cs == *ct && i < n - 1; cs++, ct++, i++)
	if (*cs == '\0')
	    return 0; 	
    return *cs - *ct; 
}
