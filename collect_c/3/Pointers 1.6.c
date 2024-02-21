#include <stdio.h>
#include <math.h>
void convert(double x,double y, double z,double *rPtr,double *tetaPtr,double *fiPtr);
main(){
	double x,y,z,r,teta,fi;
	r=0,teta=0,fi=0;
	printf("Enter cartesian coordiantes values x, y and z\n");
	scanf("%lf%lf%lf",&x,&y,&z);
	printf("x = %lf\ny = %lf\nz = %lf\nr = %lf\nteta = %lf\nfi = %lf\n",x,y,z,r,teta,fi);
	
	convert(x,y,z,&r,&teta,&fi);
	
	printf("\nAfter function called\n");
	printf("x = %lf\ny = %lf\nz = %lf\nr = %lf\nRadian form of teta = %lf\nRadian Form of fi = %lf\n",x,y,z,r,teta,fi);	
	printf("\nx = %lf\ny = %lf\nz = %lf\nr = %lf\nDegree form of teta = %lf\nDegree Form of fi = %lf\n",x,y,z,r,teta*180/M_PI,fi*180/M_PI);			
}
void convert(double x,double y, double z,double *rPtr,double *tetaPtr,double *fiPtr){
	*rPtr=sqrt(x*x+y*y+z*z);
	*tetaPtr=atan2(sqrt(x*x+y*y),z);
	*fiPtr=atan2(y,x);
}
