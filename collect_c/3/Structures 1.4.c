#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
struct Train {
	int TripID;
	int normal;  //20TL
	int elderly; // DÝSCOUNT 10%  	
	int student; // DÝSCOUNT 20% 
	int employees; // DÝSCOUNT 25% 
	double income;
};
int income (struct Train *pArray);
main(){
	struct Train t[10];
	int i;
	for(i=0;i<SIZE;i++){
		t[i].TripID=i+1;
		t[i].normal=5+rand()%71;
		t[i].elderly=5+rand()%71;
		t[i].employees=5+rand()%71;
		t[i].student=5+rand()%71;
		t[i].income=0;
	}
printf("TripID Normal Elderly Student Employee Income\n");
	for (i=0;i<10;i++)
		printf("%6d %6d %7d %7d %9d %9.2lf\n",t[i].TripID,t[i].normal,t[i].elderly,t[i].student,t[i].employees,t[i].income);
	
	 income(t);
	
printf("TripID Normal Elderly Student Employee Income\n");
	for (i=0;i<10;i++)
		printf("%6d %6d %7d %7d %9d %9.2lf\n",t[i].TripID,t[i].normal,t[i].elderly,t[i].student,t[i].employees,t[i].income);
	return 0;
}
int income (struct Train *pArray){
	int i,pass;
for(i=0;i<10;i++)
	(pArray+i)->income=(pArray[i].normal)*20+(pArray[i].elderly)*18+(pArray[i].student)*16+(pArray[i].employees)*15;
		
		
	for(pass=0;pass<10-1;pass++){
		for(i=0;i<10-1;i++){
			if(pArray[i].income>pArray[i+1].income){
				struct Train hold=pArray[i];
				pArray[i]=pArray[i+1];
				pArray[i+1]=hold;
			}
		}
	}
}
