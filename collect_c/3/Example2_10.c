 #include<stdio.h>

void function_strcat(char s[], char t[]);

main() {
	
	int c, i;
	char s[1000], t[500];
	
	for (i = 0; (c = getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;
	
	for (i = 0; (c = getchar()) != EOF && c!='\n'; ++i)
		t[i] = c;
	
	function_strcat(s, t);
	
	printf ("\n%s", s);

}
 
 /* strcat: concatenate t to end of s; s must be big enough */
void function_strcat(char s[], char t[]) { 

	int i, j;
	i = j = 0;
	
	while (s[i] != '\0') /* find end of s */
		i++;
		
	while ((s[i++] = t[j++]) != '\0'); /* copy t */
	
 } 

