#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30
int linearSearch(const int array[],int size,int k);

main(){
	srand(time(NULL));
	int a[SIZE]={};
	int i,key,position;
	
	for(i=0;i<SIZE;i++){
		a[i]=1+rand()%30;
		printf("%3d",a[i]);
		if(i%10==9)
			printf("\n");
	}
	
	printf("Enter the key:\n");
	scanf("%d",&key);
	position=linearSearch(a,SIZE,key);
	if(position!=-1)
		printf("\nFound value in position %d\n",position);
	else
		printf("\nValue not found");
		
	
}
int linearSearch(const int array[],int size,int k){
	int cnt;
	for(cnt=0;cnt<size;cnt++){
		if(array[cnt]==k)
			return cnt;
	}
	return -1;
}
