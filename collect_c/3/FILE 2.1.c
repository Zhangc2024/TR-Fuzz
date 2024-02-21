#include <stdio.h>
struct Grade{
	int number;
	char name[30];
	int q1;
	int q2;
	int q3;
	int mt;
	int final;
	double avg;
};
main(){
	struct Grade grd={0,"",0,0,0,0,0,0.0};
	FILE *wfptr;
	if((wfptr=fopen("exp7-1.dat","w"))==NULL)
		printf("File could not be opened\n");
	else{
		printf("enter number of student between 1 to 5 to stop enter 0\n");
		scanf("%d",&grd.number);
		while(grd.number!=0){
			printf("Enter name and grades:\n");
			scanf("%s%d%d%d%d%d%lf",grd.name,&grd.q1,&grd.q2,&grd.q3,&grd.mt,&grd.final,&grd.avg);
			fprintf(wfptr,"%3d  %s  %3d  %3d  %3d  %3d  %3d  %3.2lf\n",grd.number,grd.name,grd.q1,grd.q2,grd.q3,grd.mt,grd.final,grd.avg);
			printf("enter number of student between 1 to 5 to stop enter 0\n");
			scanf("%d",&grd.number);
		}
		fclose(wfptr);	
	}	
	
}
