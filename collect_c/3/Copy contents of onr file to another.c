/*Copy contents of onr file to another*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	FILE *fp1,*fp2;
	char ch;
	fp1=fopen("c:\\yoshikazu\\a.txt","r");
	fp2=fopen("c:\\yoshikazu\\b.txt","w");
	if(fp1==NULL || fp2==NULL)
	{
		printf("File does not exist");
		exit(1);
	}
	while(1)
	{
		ch=fgetc(fp1);
		if(feof(fp1))
			break;
		fputc(ch,fp2);	
	}
	fclose(fp1);
	fclose(fp2);
	getch();
	return 0;
}

