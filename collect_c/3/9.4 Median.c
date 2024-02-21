#include <stdio.h>
#include <math.h>
#define SIZE 9
void bubbleSort(int array[],int size);
int median(int array[],int size);
main(){
	int a[SIZE]={2,6,4,8,10,12,89,68,45};
	int i,med;
	
	printf("Data items in original order:\n");
	for(i=0;i<SIZE;i++)
		printf("%3d",a[i]);
	
	bubbleSort(a,SIZE);
	printf("\n\nData items in original order:\n");
	for(i=0;i<SIZE;i++)
		printf("%3d",a[i]);	
			
	med=median(a,SIZE);
	printf("\n\nMedian of the array is %d",med);
	
}
void bubbleSort(int array[],int size){
	int hold,pass,j;
	for(pass=0;pass<size-1;pass++){
		for(j=0;j<size-1;j++){
			if(array[j]>array[j+1]){
				hold=array[j];
				array[j]=array[j+1];
				array[j+1]=hold;
			}
		}
	}
	
}
int median(int array[],int size){
	return array[size/2];
}
