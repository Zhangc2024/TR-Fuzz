#include <stdio.h>

void CallByReference(int *aPtr,int *bPtr,int c);
main(){
	int a=5,b,c;
	CallByReference(&a,&b,c);
	
	printf("After function call\n");
	printf("a is %d addres is %p\n",a,&a);
	printf("b is %d addres is %p\n",b,&b);
	printf("c is %d addres is %p\n",c,&c);
	
	
}
void CallByReference(int *aPtr,int *bPtr,int c){
	printf("*aPtr = %d aPtr = %p\n",*aPtr,aPtr);
	*bPtr=7;
	c=*aPtr**bPtr;
	printf("c in function = %p\n",&c);
	
}
