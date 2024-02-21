#include <stdio.h>
#define SIZE 10
void bubbleSort(int a[],int size);
main(){
	int array[SIZE]={3,8,20,10,15,85,9,50,42,12};
	int i;
	
	printf("\nData items in original order\n");
	for(i=0;i<SIZE;i++)
		printf("%4d",array[i]);
	bubbleSort(array,SIZE);
		
	printf("\nData items in ascending order\n");
	for(i=0;i<SIZE;i++)
		printf("%4d",array[i]);	
	
	
	
	
}
void bubbleSort(int a[],int size){
	int pass=0,j,hold;
	
	for(pass=0;pass<size-1;pass++){
		for(j=0;j<size-1;j++){
			if(a[j]>a[j+1]){
				hold=a[j];
				a[j]=a[j+1];
				a[j+1]=hold;
			}
		}
	}
}
