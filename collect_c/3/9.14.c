#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#define SIZE 10
void printArray(const int array[],int size);
void bubbleSort(int array[],int size);
void EvenOrOdd(int array[],int size);
main(){
	srand(time(NULL));
	int numbers[SIZE]={};
	int i;
	for(i=0;i<SIZE;i++)
		numbers[i]=8+rand()%12;
	printf("Original Array is:\n");	
	printArray(numbers,SIZE);
	printf("\n\n");
	printf("Data items in ascending order:\n");
	bubbleSort(numbers,SIZE);
	printArray(numbers,SIZE);
	printf("\n\n");
	EvenOrOdd(numbers,SIZE);
	printf("Data items that in the question wanted order:\n");
	printArray(numbers,SIZE);
	
}
void printArray(const int array[],int size){
	int i;
	for(i=0;i<size;i++)
		printf("%4d",array[i]);
}
void bubbleSort(int array[],int size){
	int pass,j,hold;
	
	for(pass=0;pass<size-1;pass++){
		for(j=0;j<size-1;j++){
			if(array[j]>array[j+1]){
				hold=array[j+1];
				array[j+1]=array[j];
				array[j]=hold;
			}
		}
	}
	
}
void EvenOrOdd(int array[],int size){
	int i,j=0,k=0;
	for(i=0;i<size;i++){
		if(array[i]%2==0)
			j++;
		else
			k++;	
	}
	int even[j];
	int odd[k];
	int m=0,n=0;
	for(i=0;i<size;i++){
		if(array[i]%2==0){
			even[m]=array[i];
			m++;
		}
		else{
			odd[n]=array[i];
			n++;		
		}
	}
	i=0,m=0,n=0;
	if(array[0]%2==0){
		for(i=0;i<j;i++){
			array[i]=even[m];
			m++;
		}
		for(i=j;i<size;i++){
			array[i]=odd[n];
			n++;
		}
		m=0,n=0;
	}

	else{
		for(i=0;i<k;i++){
			array[i]=odd[n];
			n++;
		}
		for(i=k;i<size;i++){
			array[i]=even[m];
			m++;
		}
		
		
	}

	
}
