#include <stdio.h>
struct student {
	int number;
	char name[30];
	double GPA;
};

main(){
	struct student std={0,"",0.0};
	int i;
	FILE *wfptr;
	if((wfptr=fopen("std.dat","wb"))==NULL)
		printf("File could not be opened\n");
	else{
		for(i=1;i<=5;i++){
			fwrite(&std,sizeof(struct student),1,wfptr);
		}
		
		printf("Enter number of student between 1 to 5, and 0 to stop\n");
		scanf("%d",&std.number);
		while(std.number!=0){
			printf("Enter name and GPA\n");
			scanf("%s%lf",std.name,&std.GPA);
			fseek(wfptr,(std.number-1)*sizeof(struct student),SEEK_SET);
			fwrite(&std,sizeof(struct student),1,wfptr);
			printf("Enter number of student between 1 to 5, and 0 to stop\n");
			scanf("%d",&std.number);
		}
		fclose(wfptr);
	}	
	
	
}
