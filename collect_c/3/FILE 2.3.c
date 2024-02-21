#include <stdio.h>
#include <math.h>
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
	struct Grade grd[3]={0,"",0,0,0,0,0,0.0};
	FILE *wfptr;
	int i;
	if((wfptr=fopen("exp7-2.dat","w"))==NULL)
		printf("File could not be opened\n");
	else{
		for(i=0;i<3;i++){
			printf("Enter value for grd structure\n");
			scanf("%d%s%d%d%d%d%d%lf",&grd[i].number,grd[i].name,&grd[i].q1,&grd[i].q2,&grd[i].q3,&grd[i].mt,&grd[i].final,&grd[i].avg);
			fprintf(wfptr,"%4d %4s %4d %4d %4d %4d %d4 %4.2lf\n",grd[i].number,grd[i].name,grd[i].q1,grd[i].q2,grd[i].q3,grd[i].mt,grd[i].final,grd[i].avg);
		}
		fclose(wfptr);
	}	
	
	
	
}
