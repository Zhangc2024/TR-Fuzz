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
	if((wfptr=fopen("exp7-3.dat","wb"))==NULL)
		printf("File could not be opened\n");
	else{
		
		for(i=0;i<3;i++){
			scanf("%d%s%d%d%d%d%d%lf",&grd[i].number,grd[i].name,&grd[i].q1,&grd[i].q2,&grd[i].q3,&grd[i].mt,&grd[i].final,&grd[i].avg);
			fseek(wfptr,i*sizeof(struct Grade),SEEK_SET);
			fwrite(&grd[i],sizeof(struct Grade),1,wfptr);
		}
		fclose(wfptr);
	}	
}
