/*Additional Format Specifiers*/
#include<stdio.h>
#include<conio.h>
int main()
{
	char s1 [20];
	printf("Enter Your Name");
	scanf("%s",s1);  //DOES NOT READ SPACE
	scanf("%[^\n]",s1); //TERMINATES INPUT AND ENTER
	scanf("%[^m]",s1); //TAKES INPUT UNTIL USER PRESSES m
	scanf("%[^0-9]",s1) //TERMINATES WHEN DIGIT IS ENTERED
	scanf("%[a-z,A-Z, ]",s1) //TAKES INPUT OF ALPHABETS AND SPACE ONLY
	scanf("%[^mta]",s1) //DOES NOT READ CHARACTERS INPUT AFTER m,t OR a
	printf("%s",s1);
	getch();
	return 0;
}

