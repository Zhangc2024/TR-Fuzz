#include <stdio.h>
#include <stdlib.h>

main(){
	
	char string[100];
	printf("Enter the string:\n");
	gets(string);
	int size=0,i=0,j=0,k=0;
	int temp=0,hold=0;
	for(i=0;string[i]!='\0';i++){
		size++;
	}
	printf("Size is %d\n\n",size);
	
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(string[i]==string[j]){
				hold++;
				
			}		
		}
		for(k=0;k<i;k++){
			if(string[i]==string[k] ){
					temp++;
		
			}
		}
		if(temp==0 ){
			printf("%c den %d tane var\n",string[i],hold);		
		}
		temp=0;
		hold=0;
	}
	
	
	
	
	
	
}
