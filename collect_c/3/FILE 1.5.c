#include <stdio.h>
main(){
	double dist,ang,X,Y;
	int i,readingID;
	FILE  *wfptr;
	if((wfptr=fopen("readings.dat","r+"))==NULL)	
		printf("File could not be opened\n");
	else{
		printf("ReadingID\tDist\tAng\tX\tY\n");
		fscanf(wfptr,"%d%lf%lf%lf%lf",&readingID,&dist,&ang,&X,&Y);
		while(!feof(wfptr)){
			printf("%9d %8.2lf %7.2lf %6.2lf %8.2lf\n",readingID,dist,ang,X,Y);
			fscanf(wfptr,"%d%lf%lf%lf%lf",&readingID,&dist,&ang,&X,&Y);
		}
		fclose(wfptr);
	}	
	return 0;
}
