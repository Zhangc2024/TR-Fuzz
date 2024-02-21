/* Exercise 3-2 */

/* escape(s, t): conversts characters like the newline and tab
   into visible escape sequences like \n and \t as it copies
   the string t to s. 
   esctochar(s, t): the other way around. 
*/

#include <stdio.h>
#define MAX_STR_LEN 1024

void escape(char s[], char t[]); 
void esctochar(char s[], char t[]); 

int main()
{
    char s[MAX_STR_LEN];
    char s1[MAX_STR_LEN];
    escape(s, "Hello world\n");
    printf("%s", s); 
    esctochar(s1, s); 
    printf("%s", s1); 
    escape(s, "\a\b\f\n\r\t\vabcdefgh\n");
    printf("%s", s);
    esctochar(s1, s); 
    printf("%s", s1);    
}

/* escape(s, t): conversts characters like the newline and tab
   into visible escape sequences like \n and \t as it copies
   the string t to s. 
*/
void escape(char s[], char t[])
{
    int i, j; 
    i = j = 0; 
    while (t[i] != '\0') {
	switch (t[i]) {
	case '\a':
	    s[j++] = '\\'; 
	    s[j++] = 'a'; 
	    break;
	case '\b':
	    s[j++] = '\\'; 
	    s[j++] = 'b'; 
	    break;
	case '\f':
	    s[j++] = '\\'; 
	    s[j++] = 'f'; 
	    break;
	case '\n':
	    s[j++] = '\\'; 
	    s[j++] = 'n'; 
	    break; 
	case '\r':
	    s[j++] = '\\'; 
	    s[j++] = 'r'; 
	    break;
	case '\t':
	    s[j++] = '\\'; 
	    s[j++] = 't'; 
	    break; 
	case '\v':
	    s[j++] = '\\'; 
	    s[j++] = 'v'; 
	    break;
	default:
	    s[j++] = t[i];
	    break; 
	}
	i++; 
    }

    s[j] = '\0';
}

/* esctochar(s, t): convert character tokens such as \t and \n to the tab
   and new line characters in t when copying t to s. 
*/
void esctochar(char s[], char t[])
{
    int i, j; 
    i = j = 0; 
    while (t[i] != '\0') {
	if (t[i] == '\\') {
	    switch (t[++i]) {
	    case 'a':
		s[j++] = '\a'; 
		break; 
	    case 'b':
		s[j++] = '\b'; 
		break;
	    case 'f':
		s[j++] = '\f'; 
		break;
	    case 'n':
		s[j++] = '\n'; 
		break;
	    case 'r':
		s[j++] = '\r'; 
		break;
	    case 't':
		s[j++] = '\t'; 
		break;
	    case 'v':
		s[j++] = '\v'; 
		break;
	    default:
		s[j++] = '\\';
		s[j++] = t[i]; 
		break; 
	    }
	}
	else
	{
	    s[j++] = t[i]; 
	}
	i++; 
    }
    s[j] = '\0';
}
