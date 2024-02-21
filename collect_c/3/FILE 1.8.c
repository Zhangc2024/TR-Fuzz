#include <stdio.h>
#include <string.h>
struct student{
	int number;
	char name[30];
	double GPA;
};
main(){
	struct student std={0,"",0.0};
	int i;
	FILE *wfptr;
	if((wfptr=fopen("mehmet.dat","rb+"))==NULL)
		printf("File could not be opened\n");
	else{
		printf("Enter number of student between 1 to 5, 0 to stop\n");
		scanf("%d",&std.number);
		while(std.number!=0){
			fseek(wfptr,(std.number-1)*sizeof(struct student),SEEK_SET);
			std.number=0;
			strcpy(std.name,"");
			std.GPA=0.0;
			printf("Enter name and GPA\n");
			scanf("%s%lf",std.name,&std.GPA);
			fwrite(&std,sizeof(struct student),1,wfptr);
			printf("Enter number of student between 1 to 5, 0 to stop\n");
			scanf("%d",&std.number);					
		}
		fclose(wfptr);
	}	
	
}                   
