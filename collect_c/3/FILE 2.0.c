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
	int i;
	FILE *wfptr;
	for(i=0;i<10;i++){
		read[i].ReadingID=i+1;
		read[i].dist=2+rand()%5;
		read[i].ang=rand()%181;
		read[i].x=0;
		read[i].y=0;
	}
	if((wfptr=fopen("hw6-2.dat","wb"))==NULL)
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
	struct Reading sorted[20];
	i=0;
	if((rfptr=fopen("hw6-2.dat","rb"))==NULL)
		printf("File could not be opened\n");
	else {
		while(1){
			if(!fread(&sorted[i],sizeof(struct Reading),1,rfptr))
				break;		
			i++;	
		}
		fclose(rfptr);	
	}	
	for(i=0;i<20;i++)
		printf("%4d %4.2lf %4d %4.2lf %4.2lf\n",sorted[i].ReadingID,sorted[i].dist,sorted[i].ang,sorted[i].x,sorted[i].y);
		int pass;
	for(pass=0;pass<20-1;pass++){
		for(i=0;i<20-1;i++){
			if(sorted[i].ang<sorted[i+1].ang){
				struct Reading hold=sorted[i];
				sorted[i]=sorted[i+1];
				sorted[i+1]=hold;
			}
		}
	}
	printf("\n\nSorted structure array is:\n");
	for(i=0;i<20;i++)
		printf("%4d %4.2lf %4d %4.2lf %4.2lf\n",sorted[i].ReadingID,sorted[i].dist,sorted[i].ang,sorted[i].x,sorted[i].y);
	
	
}
