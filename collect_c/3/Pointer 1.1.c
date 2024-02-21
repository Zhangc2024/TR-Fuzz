#include <stdio.h>
void CallByReference(int *nPtr);
main(){
	int number=5;
	
	CallByReference(&number);
	printf("After funtion called\n");
	printf("number is %d Adress is %p",number,&number);

}
void CallByReference(int *nPtr){
	printf("*nPtr is %d nPtr is %p\n",*nPtr,nPtr);
	*nPtr=*nPtr**nPtr**nPtr;
	printf("After the execuation\n");
	
	printf("*nPtr is %d nPtr is %p\n",*nPtr,nPtr);
	
}
