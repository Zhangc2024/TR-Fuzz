#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
double geoMean(int shifting, int scalling);
main(){
	srand(time(NULL));
	int sf,sc;
	double func;
	printf("Enter value for shifting and scalling:\n");
	scanf("%d%d",&sf,&sc);
	func=geoMean(sf,sc);
	printf("\nResult is %lf",func);
}
double geoMean(int shifting, int scalling){
	int i,x;
	double y=1.00;
	double z=1.0/6.0;
	for(i=1;i<=6;i++){
		x=shifting+rand()%scalling;
		printf("The %d'th random number is %d\n",i,x);
		y=pow(x,z)*y;

	}
	return y;
}
