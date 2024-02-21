#include <stdio.h>

void c(int ar);

main(){
		int a=1;
		int size=10;
		int i=0;
		printf("Original\n\n");

			printf("%3d",a);
		c(a);
		printf("\nChanged\n");
	
			printf("%3d",a);
}
void c(int ar){
	int i=0;
		ar=i+20;
	printf("\nar\n");	
		printf("%3d",ar);
	
}
