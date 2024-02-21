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
	struct Grade grd[3];
	FILE *wfptr;
	int i=0;
	if((wfptr=fopen("exp7-2.dat","r"))==NULL)
		printf("File could not be opened\n");
	else{
		fscanf(wfptr,"%d%s%d%d%d%d%d%lf",&grd[i].number,grd[i].name,&grd[i].q1,&grd[i].q2,&grd[i].q3,&grd[i].mt,&grd[i].final,&grd[i].avg);
		if(!feof(wfptr)){
			i++;
			fscanf(wfptr,"%d%s%d%d%d%d%d%lf",&grd[i].number,grd[i].name,&grd[i].q1,&grd[i].q2,&grd[i].q3,&grd[i].mt,&grd[i].final,&grd[i].avg);
		}
		fclose(wfptr);	
	}	
	for(i=0;i<3;i++)
			fprintf(stdout,"%3d %s %3d %3d %3d %3d %3d %3.2lf\n",grd[i].number,grd[i].name,grd[i].q1,grd[i].q2,grd[i].q3,grd[i].mt,grd[i].final,grd[i].avg);
	if((wfptr=fopen("exp7-2.dat","w"))==NULL)
		printf("File could not be opened\n");
	else{
		for(i=0;i<3;i++){
			if(grd[i].number==1){
				grd[i].q1=100;
				grd[i].q2=100;
				grd[i].q3=100;
				grd[i].mt=100;
				grd[i].final=100;
				grd[i].avg=100;
			}
			fprintf(wfptr,"%3d %s %3d %3d %3d %3d %3d %3.2lf\n",grd[i].number,grd[i].name,grd[i].q1,grd[i].q2,grd[i].q3,grd[i].mt,grd[i].final,grd[i].avg);
			fprintf(stdout,"%3d %s %3d %3d %3d %3d %3d %3.2lf\n",grd[i].number,grd[i].name,grd[i].q1,grd[i].q2,grd[i].q3,grd[i].mt,grd[i].final,grd[i].avg);
		}	
		fclose(wfptr);
	}	
	
}
