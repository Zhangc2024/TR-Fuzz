#include <stdio.h>
#include <ctype.h>
#include <string.h>

main(){
	printf("**********************************\n");
	printf("*           HOMEWORK 3           *\n");
	printf("**********************************\n");
	printf("*             1.SORU             *\n");
	printf("**********************************\n");
	char c[41]={};
	int i,cnt=0;
	for(i=0;i<40;i++)
		c[i]=33+rand()%94;
	c[40]='\0';
	printf("String is:\n%s",c);
	for(i=0;i<40;i++){
		if(!isalnum(c[i]))
		cnt++;
	}
	printf("\nThe result is %d\n",cnt);
	printf("**********************************\n");
	printf("*             2.SORU             *\n");
	printf("**********************************\n");
	printf("*First Solution*\n");
	char string[]=" A carefully reasoned, ordered sentence tells it clearly";
	char word[10]={};
	char *tokenPtr;
	i=0;
	tokenPtr=strtok(string," ");
	printf("***%s****",*tokenPtr);
	while(tokenPtr!=NULL){
		printf("%c\n",*tokenPtr);
		word[i]=*tokenPtr;
		tokenPtr=strtok(NULL," ");
		i++;
	}
	word[i]='\0';
	printf("The word is: %s\n\n",word);
	printf("*Second Solution*\n\n");
	char string1[]=" A carefully reasoned, ordered sentence tells it clearly";
	int j=0;
	char wrd[10]={};
	i=0;
	while(string1[i]!='\0'){
		if(string1[i]==' '){
			wrd[j]=string1[i+1];
			j++;
		}
		i++;
	}
	wrd[j]='\0';
		printf("The word is: %s\n\n",wrd);
		
	printf("**********************************\n");
	printf("*             3.SORU             *\n");
	printf("**********************************\n");	
	char s1[100]="This is a test sentence Eskisehir is beautiful city in Turkey";
	printf("The string is %s\n",s1);
	char *tokenPtr1;
	tokenPtr1=strtok(s1,"i");
	while(tokenPtr1!=NULL){
		printf("%s\n",tokenPtr1);
		tokenPtr1=strtok(NULL,"i");
	}	
		
	
}
