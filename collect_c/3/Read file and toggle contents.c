/*Read file and toggle contents*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch;
	int i;
	fp=fopen("C:\\Yoshikazu\\a.txt","r+");   
	//"file location\\file name","mode of opening"
	if(fp==NULL)
	{
		printf("File does not exists");
		getch();
		return 0;
	}
	while(1)
	{
		//i=ftell(fp)
		ch=fgetc(fp);
		if(feof(fp))
		  break;
		if(ch>=65&&ch<=90)
		  ch+=32;
		else if(ch>=97&&ch<=122)
		  ch-=32;
		fseek(fp,-1,SEEK_CUR);
		fputc(ch,fp);
		fflush(fp);      
	}
	fclose(fp);
	getch();
	return 0; 
}

