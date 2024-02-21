#include <stdio.h>
#include <string.h>

main(){
	char string[]="This is a sentence with 7 tokens";
	char *tokenPtr;
	printf("The tokens are:\n");
	tokenPtr=strtok(string," ");
//	while(tokenPtr!=NULL){
		printf("%s\n",tokenPtr);
//		tokenPtr=strtok(NULL," ");
//	}
	printf("\n\n\n\n");
	char string1[]="- This, a sample string. www.ogu.edu.tr";
	char *tokenPtr1;
	printf("The tokens are:\n");
	tokenPtr1=strtok(string1," ,.-");
	while(tokenPtr1!=NULL){
		printf("%s\n",tokenPtr1);
		tokenPtr1=strtok(NULL," ,.-");
	}	
	printf("\n\n\n\n");
	const char *s1="abcdefghijklmonprstuvwxyz";
	const char *s2="Four";
	const char *s3="Boston";
	printf("The length of %s is %d\n",s1,strlen(s1));
	printf("The length of %s is %d\n",s2,strlen(s2));
	printf("The length of %s is %d\n",s3,strlen(s3));
}
