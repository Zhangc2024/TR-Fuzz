#include <stdio.h>
#include <math.h>
main(){
	double dist,ang,X,Y;
	int i,ReadingID;
	
	FILE *wfptr;
	if((wfptr=fopen("readings.dat","w"))==NULL)	
		printf("File could not be opened\n");
	else{
		for(i=0;i<10;i++){
			ReadingID=i+1;
			dist=4;
			ang=rand()%181;
			X=dist*cos(ang*M_PI/180);
			Y=dist*sin(ang*M_PI/180);
			fprintf(wfptr,"%d %4.2lf %4.2lf %4.2lf %4.2lf\n",ReadingID,dist,ang,X,Y);
			fprintf(stdout,"%d %4.2lf %4.2lf %4.2lf %4.2lf\n",ReadingID,dist,ang,X,Y);
		}
		fclose(wfptr);
	}	
	
	
	
}
