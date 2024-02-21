#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXSTR 100
#define FOLD	4		/* fold upper and lower cases */
#define DIR		8		/* fold upper and lower cases */

void substr(char *s, char *t, int maxstr);

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
	double v1, v2;
	char str[MAXSTR];
	
	substr(s1, str, MAXSTR);	
	v1 = atof(s1);
	substr(s2, str, MAXSTR);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

/* charcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int charcmp(char *s, char *t)
{
	char a, b;
	int i, j, endpos;
	extern char option;
	extern int pos1, pos2;
	
	int fold = (option & FOLD) ? 1 : 0;
	int dir = (option & DIR) ? 1 : 0;
	
	i = j = pos1;
	if (pos2 > 0)
		endpos = pos2;
	else if ((endpos = strlen(s)) > strlen(t))
		endpos = strlen(t);
	do {
		if (dir) {
			while (i < endpos && !isalnum(s[i]) && s[i] != ' ' && s[i] != '\0')
				i++;
			while (j < endpos && !isalnum(t[j]) && t[j] != ' ' && t[j] != '\0')
				j++;
		}
		if (i < endpos && j < endpos) {
			a = fold ? tolower(s[i]) : s[i];
			i++;
			b = fold ? tolower(t[j]) : t[j];
			j++;
			if (a == b && a == '\0')
				return 0;	
		}
	} while (a == b && i < endpos && j < endpos);
	return a - b;
}
