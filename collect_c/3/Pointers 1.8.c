#include <stdio.h>
#define SIZE 4
main(){
	
	int b[SIZE]={10,20,30,40};
	int *bPtr=b;
	int i, offset;
	printf("Array b printed with:\nArray subscript notation\n");
	for(i=0;i<SIZE;i++)
		printf("b[%d] = %d\n",i,b[i]);
	printf("Pointer offset notation where the pointer is the array\n");
	for(offset=0;offset<SIZE;offset++)
		printf("*(b + %d) = %d\n",offset,*(b+offset));
	printf("Pointer subscript notation\n");		
	for(i=0;i<SIZE;i++)
		printf("bPtr[%d] = %d\n",i,bPtr[i]);
	printf("Pointer offset notation \n");
	for(offset=0;offset<SIZE;offset++)
		printf("*(bPtr + %d) = %d\n",offset,*(bPtr+offset));			
	
	
}
