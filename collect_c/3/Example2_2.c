#include<stdio.h>
#include<string.h>

int funtion_strlen(char s[]); 

main() {
	
	int i, i2;
	char c[1000];
	
	scanf(" %[^\n]", &c); //" %[^\n]".- almacena una cadena de caracteres con espacios
	
	i = funtion_strlen(c);
	
	i2 = strlen(c);
	
	printf("%i\n%i", i, i2);
		
}

 /* strlen: return length of s */
int funtion_strlen(char s[]) {

	int i;
	while (s[i] != '\0')
		++i;
	
	return i;
	
 } 
