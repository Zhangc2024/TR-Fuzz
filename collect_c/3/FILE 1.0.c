#include <stdio.h>

main(){
	int number;
	char name[30];
	double GPA;
	FILE *wfptr;
	
	if((wfptr=fopen("students.dat","w"))==NULL)
		printf("File could not open be opened\n");
	else{
		printf("Enter number, name , GPA\n");
		scanf("%d%s%lf",&number,name,&GPA);
		while(!feof(stdin)){
			fprintf(wfptr,"%d %s %lf\n",number,name,GPA);
			fprintf(stdout,"%d %s %lf\n",number,name,GPA);
			scanf("%d%s%lf",&number,name,&GPA);
		}
		fclose(wfptr);
	}	
	return 0;	
}
