#include <stdio.h>
struct student{
	int number;
	char name[30];
	double GPA;
};
main(){
	struct student std={0,"",0.0};
	FILE *wfptr;
	int c;
	if((wfptr=fopen("std.dat","rb"))==NULL)
		printf("File could not be opened\n");
	else{
		printf("Number\tName\tGPA\n");
		while(1){
			if(!fread(&std,sizeof(struct student),1,wfptr))
				break;
			else
				printf("%6d\t\3s\t%3.2lf\n",std.number,std.name,std.GPA);
					
		}
		fclose(wfptr);
	}	
}
