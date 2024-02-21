#include <stdio.h>
void CubeByReference(int x, int *y);
main(){
	int cube=0,count=5;
	CubeByReference(count,&cube);
	printf("count is %d cube is %d",count,cube);


}
void CubeByReference(int x, int *y){
	*y=x*x*x;
}
