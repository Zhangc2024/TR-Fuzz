 #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
struct Grade{
	int q1;
	int q2;
	int q3;
	int mt;
	int final;
	double avg;
	char *letter;
};
void histogram(struct Grade *cpArray);
main(){
	int i;
	struct Grade CP[10];
	for(i=0;i<SIZE;i++){
		CP[i].q1=rand()%101;
		CP[i].q2=rand()%101;
		CP[i].q3=rand()%101;
		CP[i].mt=rand()%101;
		CP[i].final=rand()%101;
	}
	histogram(CP);
	printf("Q1\tQ2\tQ3\tMT\tFINAL\tAVG\tLETTER\n");
	for(i=0;i<SIZE;i++){
	printf("%3d\t%3d\t%3d\t%3d\t%3d\t%3.2lf\t%s\n",CP[i].q1,CP[i].q2,CP[i].q3,CP[i].mt,CP[i].final,CP[i].avg,CP[i].letter);
	}
}
void histogram(struct Grade *cpArray){
	int i;
	for(i=0;i<SIZE;i++)
		cpArray[i].avg=cpArray[i].q1*10/100+cpArray[i].q2*10/100+cpArray[i].q3*10/100+cpArray[i].mt*25/100+cpArray[i].final*45/100;
	for(i=0;i<SIZE;i++){
	if(cpArray[i].avg>=85)
		cpArray[i].letter="AA";
	else if(cpArray[i].avg>=65 && cpArray[i].avg<85)
		cpArray[i].letter="BB";
	else if(cpArray[i].avg>=45 && cpArray[i].avg<65)
		cpArray[i].letter="CC";	
	else if(cpArray[i].avg>=35 && cpArray[i].avg<45)
		cpArray[i].letter="DD";
	else
		cpArray[i].letter="FF";
	}
	int pass;
	for(pass=0;pass<SIZE-1;pass++){
		for(i=0;i<SIZE-1;i++){
			if(cpArray[i].avg<cpArray[i+1].avg){
				struct Grade hold=cpArray[i];
				cpArray[i]=cpArray[i+1];
				cpArray[i+1]=hold;
			}
		}
	}
	int gradeHist[5]={};
	for(i=0;i<SIZE;i++){
		if(cpArray[i].letter=="AA")
			gradeHist[0]++;
		else if(cpArray[i].letter=="BB")
			gradeHist[1]++;	
		else if(cpArray[i].letter=="CC")
			gradeHist[2]++;	
		else if(cpArray[i].letter=="DD")
			gradeHist[3]++;		
		else
			gradeHist[4]++;			
	}
	int j;
	printf("AA\t\tBB\t\tCC\t\tDD\t\tFF\n");
	for(j=0;j<5;j++){
		for(i=0;i<gradeHist[j];i++)
			printf("*");
		printf("\t\t");	
	}
	printf("\n\n");

}
