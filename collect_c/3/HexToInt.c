/* Exercise 2-3 */ 

/* A function htoi(s) which conversts a string of 
   hexadecimal digits (including an optional 0x or 0X)
   into its equivalent integer value. The allowable 
   digits are 0 through 9, a through f, and A through F
*/

/* The code assumes s contains a valid hexadecimal string. 
   i.e. it is not empty and contains only the hex digits. 
   Without the optional 0X or 0x, the leading zeros are
   ignored. See test case 6. 
*/

#include <stdio.h>

#define MAXLENGTH 1000

int htoi(char s[]); 
char ctolower(char c); 
void stolower(char s[]);
int tovalue(char c); 

void copy(char to[], char from[]);

int main()
{
    printf("Hello world\n"); 
    printf("test 0: %d\n", htoi("-0xa"));
    printf("test 1: %d\n", htoi("0xA"));
    printf("test 2: %d\n", htoi("A")); 
    printf("test 3: %d\n", htoi("0XAF")); 
    printf("test 4: %d\n", htoi("16")); 
    printf("test 5: %d\n", htoi("0")); 
    printf("test 6: %d\n", htoi("0012")); 
}

/* htoi(s): convert a string of hex, s, to dec. */
/* In any practical implementation, this function
   probably should check for overflows. 
   This check is omitted here. 
 */
int htoi(char s[])
{
    char str[MAXLENGTH]; 
    copy(str, s);  /* make a copy to perform stolower */
    stolower(str); /* first convert s to have only 
		      lower case letters
		    */

    int v, sign, idx; 
    idx = 0; 
    sign = 1; 

    /* deal with the sign */
    if (str[idx] == '-') {
	sign = -1; 
	++idx; 
    }
    
    /* deal with the optional 0x */
    if (str[idx] == '0') {
	++idx; 
	if (str[idx] == '\0')
	    return 0; 
	else if (str[idx] == 'x') {
	    ++idx; /* ignore the x and move to the next char */
	}	
    } 

    /* convert each char into int and accumulate */
    v = 0; 
    while (str[idx] != '\0') {
	v = (v << 4) + tovalue(str[idx]);
	++idx; 
    }
    
    return sign * v; 
}

/* stolower(s): convert the entire string s to lower case */
void stolower(char s[])
{
    for (int i = 0; s[i] != '\0'; ++i)
	s[i] = ctolower(s[i]); 
}

/* ctolower(c): convert a char to lower. Nothing
   is done if c is not an upper case letter. 
*/
char ctolower(char c) 
{
    if (c >= 'A' && c <= 'Z')
	return c + 'a'- 'A';
    else /*do not do anything if c is not upper case*/
	return c; 
}

/* tovalue(c): convert input to hex. c must be a digit or 
   a lower case letter, i.e. [0-9a-f].
*/
int tovalue(char c) 
{
    if (c >= '0' && c <= '9')
	return c - '0'; 
    else /* c is a lower case letter */
	return c - 'a' + 10; 
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i; 
    
    i = 0; 
    while ((to[i] = from[i]) != '\0')
	++i; 
}
