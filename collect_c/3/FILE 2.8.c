#include <stdio.h>
#include <math.h>
struct Reading{
	int ReadingID;
	double dist;
	int ang;
	double x;
	double y;
	
};

main(){
	struct Reading read[10];
	struct Reading sorted[20];
	int i;
	for(i=0;i<10;i++){
		read[i].ReadingID=i+1;
		read[i].ang=rand()%180;
		read[i].dist=2+rand()%5;
		read[i].x=0.0;
		read[i].y=0.0;
	}
	FILE *wfptr;
	if((wfptr=fopen("example2.dat","wb+"))==NULL)
		printf("File could not be opened\n");
	else{
		for(i=0;i<10;i++){
			fseek(wfptr,(read[i].ReadingID-1)*sizeof(struct Reading),SEEK_SET);
			fwrite(&read[i],sizeof(struct Reading),1,wfptr);
		}
		for(i=0;i<10;i++){
			read[i].x=read[i].dist*cos(read[i].ang*M_PI/180);
			read[i].y=read[i].dist*sin(read[i].ang*M_PI/180);
		}
		for(i=0;i<10;i++){
			fseek(wfptr,(read[i].ReadingID+9)*sizeof(struct Reading),SEEK_SET);
			fwrite(&read[i],sizeof(struct Reading),1,wfptr);
		}	
	fclose(wfptr);		
}	

	
	FILE *rfptr;
	if((rfptr=fopen("example2.dat","rb"))==NULL)
		printf("File could not be opened\n");
	else{
		i=0;
		while(1){
			if(!fread(&sorted[i],sizeof(struct Reading),1,wfptr))
				break;
			else{
				fprintf(stdout,"%d\t%lf\t%d\t%lf\t%lf\n",sorted[i].ReadingID,sorted[i].dist,sorted[i].ang,sorted[i].x,sorted[i].y);
				i++;
			}
					
			
		}	
	
		fclose(rfptr);	
	}	
	
		printf("\n\n\n\nSorted:\n");	


	if((wfptr=fopen("example2.dat","w"))==NULL)
		printf("File could not be opened\n");
	else{
	int pass=0;
	for(pass=0;pass<19;pass++){
			for(i=0;i<19;i++){
				if(sorted[i].ang<sorted[i+1].ang){
					struct Reading hold=sorted[i];
					sorted[i]=sorted[i+1];
					sorted[i+1]=hold;
				}
			}
		}
	for(i=0;i<20;i++){
		fprintf(wfptr,"%d\t%lf\t%d\t%lf\t%lf\n",sorted[i].ReadingID,sorted[i].dist,sorted[i].ang,sorted[i].x,sorted[i].y);
		fprintf(stdout,"%d\t%lf\t%d\t%lf\t%lf\n",sorted[i].ReadingID,sorted[i].dist,sorted[i].ang,sorted[i].x,sorted[i].y);	
		}
		fclose(wfptr);	
	}	
	
	
	
}
