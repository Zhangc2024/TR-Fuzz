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
	if((wfptr=fopen("exp7-3.dat","rb+"))==NULL)
		printf("File could not be opened\n");
	else{
		for(i=0;i<3;i++){
			if(!fread(&grd[i],sizeof(struct Grade),1,wfptr))
				break;
			else
				fprintf(stdout,"%3d %s %3d %3d %3d %3d %3d %3.2lf\n",grd[i].number,grd[i].name,grd[i].q1,grd[i].q2,grd[i].q3,grd[i].mt,grd[i].final,grd[i].avg);	
		}
		printf("\n\n");
		grd[1].q1=100;
		grd[1].q1=100;
		grd[1].q1=100;
		grd[1].mt=100;
		grd[1].final=100;
		grd[1].avg=100;
		fseek(wfptr,1*sizeof(struct Grade),SEEK_SET);
		fwrite(&grd[1],sizeof(struct Grade),1,wfptr);	
		for(i=0;i<3;i++){
			if(!fread(&grd[i],sizeof(struct Grade),1,wfptr))
				break;
			else
				fprintf(stdout,"%3d %s %3d %3d %3d %3d %3d %3.2lf\n",grd[i].number,grd[i].name,grd[i].q1,grd[i].q2,grd[i].q3,grd[i].mt,grd[i].final,grd[i].avg);	
		}		
		fclose(wfptr);	
		
	}	
	
	
}
