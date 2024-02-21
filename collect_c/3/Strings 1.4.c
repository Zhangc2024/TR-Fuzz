#include <stdio.h>
#include <string.h>

main(){
	
	
	
	
	printf("*********************************\n");
	printf("*1- strcpy and strncpy Functions*\n");
	printf("**********************************\n\n");
	char UART_MasterMessage[] ="AT+TEMP?\n"; 
	int i=0;
	while(i<20){
		if(UART_MasterMessage[i]='\0')
			break;
		i++;	
	}
	printf("**%c**%c**%d**%d*\n",UART_MasterMessage[9],UART_MasterMessage[10],sizeof(UART_MasterMessage),i);
	
	char x[]="Happy Birthday to You";
	char y[25];
	char z[15];
	strcpy(y,x);
	strncpy(z,x,14);
	z[14]='\0';
	printf("In array x: %s\n",x);
	printf("In array y: %s\n",y);
	printf("In array z: %s\n",z);
	
	
	printf("*********************************\n");
	printf("*2- strcat and strncat Functions*\n");
	printf("**********************************\n\n");	
	
	char s1[20]="Happy ";
	char s2[]="New Year ";
	char s3[40]="";
	printf("In array s1: %s\n",s1);
	printf("In array s2: %s\n",s2);
	printf("In array s3: %s\n",s3);
	strcat(s1,s2);
	printf("After the strcat(s1,s2) In array s1: %s\n",s1);
	strncat(s3,s1,6);
	printf("After the strncat(s3,s1,6) In array s3: %s\n",s3);
	strcat(s3,s1);
	printf("In array s1: %s\n",s1);
	printf("In array s2: %s\n",s2);
	printf("In array s3: %s\n",s3);
	
	printf("*********************************\n");
	printf("*3- strcmp and strncmp Functions*\n");
	printf("**********************************\n\n");
	
	const char *c1="Happy New Year";
	const char *c2="Happy New Year";	
	const char *c3="Happy Holidays";
	printf("strcmp(c1,c2) = %d\n",strcmp(c1,c2));
	printf("strcmp(c1,c3) = %d\n",strcmp(c1,c3));
	printf("strcmp(c3,c1) = %d\n\n",strcmp(c3,c1));
	
	printf("strncmp(c1,c3,6) = %d\n",strncmp(c1,c3,6));
	printf("strncmp(c1,c3,7) = %d\n",strncmp(c1,c3,7));
	printf("strncmp(c3,c1,7) = %d\n",strncmp(c3,c1,7));	
	
	
	printf("*********************************\n");
	printf("*4- strchr and strrchr Functions*\n");
	printf("**********************************\n\n");	
	
	const char *string="This is a Test";
	char character1= 'a';
	char character2= 'z';
	if(strchr(string,character1)!=NULL)
		printf("\'%c\' was found in \"%s\"\n",character1,string);	
	else
		printf("\'%c\' was not found in \"%s\"\n",character1,string);
	if(strchr(string,character2)!=NULL)
		printf("\'%c\' was found in \"%s\"\n",character2,string);	
	else
		printf("\'%c\' was not found in \"%s\"\n",character2,string);
		
	const char *string4="A zoo many animals including zebras";
	char character3= 's';
	char character4= 'z';	
	printf("%s\n",string4);
	if(strchr(string4,character3)!=NULL)
		printf("\n%c was found\nthe string after the first occurence of %c\n%s\n",character3,character3,strchr(string4,character3));
	if(strrchr(string4,character3)!=NULL)
		printf("\n%c was found\nthe string after the last occurence of %c\n%s\n",character3,character3,strrchr(string4,character3));
	if(strchr(string4,character4)!=NULL)
		printf("\n%c was found\nthe string after the first occurence of %c\n%s\n",character4,character4,strchr(string4,character4));
	if(strrchr(string4,character4)!=NULL)
		printf("\n%c was found\nthe string after the last occurence of %c\n%s\n",character4,character4,strrchr(string4,character4));	
	
	printf("********************\n");
	printf("*5- strstr Function*\n");
	printf("********************\n\n");	
	
	const char *str="abcdefabcdef";
	const char *str1="def";
	if(strstr(str,str1)!=NULL)
		printf("\n%s was found\nthe string after the first occurence of %s\n%s\n",str1,str1,strstr(str,str1));
		
		
	printf("********************\n");
	printf("*6- strbbrk Function*\n");
	printf("********************\n\n");	
	const char *q="This is a test";
	const char *w="beware";
	const char *v="rats";
	if(strpbrk(x,y)!=NULL){
		printf("A character from \"%s\" was found in \"%s\"\n",w,q);
		printf("\'%c\' appear earliest\n",*strpbrk(q,w));
		printf("The string after the first occurence of \'%c\'\n%s\n\n",*strpbrk(q,w),strpbrk(q,w));
	}
	if(strpbrk(x,z)!=NULL){
		printf("A character from \"%s\" was found in \"%s\"\n",z,v);
		printf("\'%c\' appear earliest\n",*strpbrk(q,v));
		printf("The string after the first occurence of \'%c\'\n%s\n\n",*strpbrk(q,v),strpbrk(q,v));
	}
	

	printf("*********************************\n");
	printf("*7- strcspn and strspn Functions*\n");
	printf("**********************************\n\n");	
	
	const char *a="The value is 3.14159";
	const char *b="1234567890";
	printf("The length of the initial segment of \"%s\"\n",a);
	printf("containig no characters from \"%s\" is %d\n",b,strcspn(a,b));
	
	const char *c="The value is 3.14159";
	const char *d="aehi lsTuv";
	printf("The length of the initial segment of \"%s\"\n",c);
	printf("containig no characters from \"%s\" is %d\n",d,strspn(c,d));
		
		
	
}
