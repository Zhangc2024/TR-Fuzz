#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
int count(int n[],int size);
main(){
	int numbers[SIZE]={};
	int i;
	for(i=0;i<SIZE;i++)
		numbers[i]=-8+rand()%18;
		
	printf("Numbers:\n");	
	for(i=0;i<SIZE;i++)	
		printf("%3d",numbers[i]);
	printf("\n\n");
	int c;
	c=count(numbers,SIZE);
	printf("Total number of negative elements in array is %d",c);
	
}
int count(int n[],int size){
	int i,cnt=0;
	for(i=0;i<size;i++){
		if(n[i]<0)
			cnt++;
	}
	return cnt;
}
