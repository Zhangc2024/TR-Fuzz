#include <stdio.h>
#include <ctype.h>

main(){
	printf("According to isdigit:\n");
	if(isdigit('B'))
		printf("B is a digit\n");
	else
		printf("B is not a digit\n");	
	if(isdigit('#'))
		printf("# is a digit\n");
	else
		printf("# is not a digit\n");	
	if(isdigit('3'))
		printf("3 is a digit\n");
	else
		printf("'3' is not a digit\n");	
		
	printf("\nAccording to isalpha:\n");
	if(isalpha('A'))
		printf("A is a letter\n");
	else
		printf("A is not a letter\n");	
	if(isalpha('b'))
		printf("b is a letter\n");
	else
		printf("b is not a letter\n");	
	if(isalpha('&'))
		printf("& is a letter\n");
	else
		printf("& is not a letter\n");	
	if(isalpha('1'))
		printf("10 is a letter\n");
	else
		printf("10 is not a letter\n");	
									
	printf("\nAccording to isalnum:\n");
	if(isalnum('A'))
		printf("A is a letter or a digit\n");
	else
		printf("A is not a letter or a digit\n");		
	if(isalnum('3'))
		printf("3 is a letter or a digit\n");
	else
		printf("3 is not a letter or a digit\n");	
	if(isalnum('#'))
		printf("# is a letter or a digit\n");
	else
		printf("# is not a letter or a digit\n");	
		
	printf("\nAccording to islower:\n");
	if(islower('p'))
		printf("p is a lowercase letter\n");
	else
		printf("p is not a lowercase letter\n");		
	if(islower('S'))
		printf("S is a lowercase letter\n");
	else
		printf("S is not a lowercase letter\n");
	if(islower('!'))
		printf("! is a lowercase letter\n");
	else
		printf("! is not a lowercase letter\n");	
		
	printf("\nAccording to isupper:\n");
	if(isupper('D'))
		printf("D is a uppercase letter\n");
	else
		printf("D is not a uppercase letter\n");	
	if(isupper('5'))
		printf("5 is a uppercase letter\n");
	else
		printf("5 is not a uppercase letter\n");	
	if(isupper('%'))
		printf("% is a uppercase letter\n");
	else
		printf("% is not a uppercase letter\n");
			
	printf("\n\n");
	printf("u converted to uppercase is %c\n",toupper('u'));			
	printf("7 converted to uppercase is %c\n",toupper('7'));
	printf("$ converted to uppercase is %c\n",toupper('$'));
	printf("M converted to lowercase is %c\n",tolower('M'));						
}
