/* Exercise 3-3 */

#include <stdio.h>
#define MAX_STR_LEN 1024
#define TRUE 1
#define FALSE 0

void expand(char s1[], char s2[]); 

int main() 
{
    char s1[MAX_STR_LEN] = "a-z"; 
    char s2[MAX_STR_LEN] = ""; 
    expand(s1, s2); 
    printf("%s\n", s2); 

    char s3[MAX_STR_LEN] = "-a-z-"; 
    char s4[MAX_STR_LEN] = ""; 
    expand(s3, s4); 
    printf("%s\n", s4); 

    char s5[MAX_STR_LEN] = "a-b-c"; 
    char s6[MAX_STR_LEN] = ""; 
    expand(s5, s6); 
    printf("%s\n", s6); 

    char s7[MAX_STR_LEN] = "a-z0-9"; 
    char s8[MAX_STR_LEN] = ""; 
    expand(s7, s8); 
    printf("%s\n", s8);
}

/* expand(s1, s2): expand notations like a-z in string s1
   into the equivalent complete list in s2. Allow for letters
   of either case and digits, and be prepared to handle cases 
   like a-b-c and a-z0-9 and -a-z. Leading and trailing - is taken
   literally. 
*/
void expand(char s1[], char s2[])
{
    int i, j, k, curr_idx; 
    i = j = k = curr_idx = 0; 

    int match = 0;     
    while (s1[i] != '\0') {
	int start, end;  
	start = end = 0; 
	j = i; 
	match = TRUE; 
	while (s1[j] != '\0' && match) {
	    start = s1[j++];
	    if (s1[j] != '-') {
		match = FALSE; 
		end = s1[j]; 
	    }
	    else {
	        int c = s1[++j];
		if (c != '\0') {
		    end = c; 
		    match = TRUE; 
		    break; 
		}
		else {
		    end = '-'; 
		    match = FALSE; 
		}
	    }
	}
	
	if (match) {
	    for (k = curr_idx; k < end - start + curr_idx; k++) {
		s2[k] = start + k - curr_idx; 
	    }
	}
	else {
	    for (k = curr_idx; k < j - i + curr_idx; k++) {
		s2[k] = s1[i + k - curr_idx]; 
	    }
	}
	curr_idx = k; 

	i = j;
    }

    s2[curr_idx] = '\0'; 
}
