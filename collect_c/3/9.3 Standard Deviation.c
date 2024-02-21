#include <stdio.h>
#include <math.h>
#define SIZE 10

double mean(const int a[],int size);
double SD (const int a[],int size, double m);
main(){
	
	int array[SIZE]={2,6,4,8,10,12,89,68,45,37};
	int i;
	double avg, std;
	
	printf("Data items:\n");
	for(i=0;i<SIZE;i++)
		printf("%4d",array[i]);
	avg=mean(array,SIZE);
	printf("\n\nMean of the array is %lf\n",avg);	
	std=SD(array,SIZE,avg);
	printf("\n\nSD of the array is %lf\n",std);	
	
	
}
double mean(const int a[],int size){
	int i;
	double sum;
	for(i=0;i<size;i++)
		sum=sum+a[i];
	return sum/size;
}
double SD (const int a[],int size, double m){
	int i;
	double sum=0;
	for(i=0;i<size;i++)
		sum=sum+pow((a[i]-m),2);
	return sqrt(sum/size);	
}
