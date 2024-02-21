#include <stdio.h>

main(){
	int number;
	char name[30];
	double GPA;
	FILE *wfptr;
	
	if((wfptr=fopen("students.dat","r"))==NULL)
		printf("File could not open be opened\n");
	else{
		printf("Number	Name         GPA\n");
		fscanf(wfptr,"%d%s%lf",&number,name,&GPA);
		while(!feof(wfptr)){
		printf("%6d%8s%10.2lf\n",number,name,GPA);
		fscanf(wfptr,"%d%s%lf",&number,name,&GPA);
		}
		fclose(wfptr);
		
	}
	
}
