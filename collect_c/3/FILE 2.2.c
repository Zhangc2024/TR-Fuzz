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
	struct Grade grd={0,"",0,0,0,0,0,0.0};
	FILE *wfptr;
	if((wfptr=fopen("exp7-1.dat","w+"))==NULL)
		printf("File could not be opened\n");
	else{
		fscanf(wfptr,"%d%s%d%d%d%d%d%lf",&grd.number,grd.name,&grd.q1,&grd.q2,&grd.q3,&grd.mt,&grd.final,&grd.avg);
		if(grd.number==1){
			grd.q1=100,grd.q2=100,grd.q3=100,grd.mt=100,grd.final=100,grd.avg=100;
			fprintf(wfptr,"%3d  %s  %3d  %3d  %3d  %3d  %3d  %3.2lf\n",grd.number,grd.name,grd.q1,grd.q2,grd.q3,grd.mt,grd.final,grd.avg);
			fprintf(stdout,"%3d  %s  %3d  %3d  %3d  %3d  %3d  %3.2lf\n",grd.number,grd.name,grd.q1,grd.q2,grd.q3,grd.mt,grd.final,grd.avg);
		}
		while(!feof(wfptr)){
			fscanf(wfptr,"%d%s%d%d%d%d%d%lf",&grd.number,grd.name,&grd.q1,&grd.q2,&grd.q3,&grd.mt,&grd.final,&grd.avg);
			if(grd.number==1){
			grd.q1=100,grd.q2=100,grd.q3=100,grd.mt=100,grd.final=100,grd.avg=100;
			fprintf(wfptr,"%3d  %s  %3d  %3d  %3d  %3d  %3d  %3.2lf\n",grd.number,grd.name,grd.q1,grd.q2,grd.q3,grd.mt,grd.final,grd.avg);
			fprintf(stdout,"%3d  %s  %3d  %3d  %3d  %3d  %3d  %3.2lf\n",grd.number,grd.name,grd.q1,grd.q2,grd.q3,grd.mt,grd.final,grd.avg);
			}
		}
	fclose(wfptr);
	}
}
