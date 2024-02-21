#include <stdio.h>
#include <math.h>
void rotate(double xc,double yc, double teta, double *xrPtr, double *yrPtr);
main(){
	double xc,yc,teta,xr,yr;
	xr=0,yr=0;
	printf("Enter current cordinates: xc, yc and rotation angel: teta\n");
	scanf("%lf%lf%lf",&xc,&yc,&teta);
	printf("xc = %lf\nyc = %lf\nteta = %lf\nxr = %lf\nyr = %lf\n",xc,yc,teta,xr,yr);
	rotate(xc,yc,teta,&xr,&yr);
	printf("After Rotate Function called:\n");
	printf("xc = %lf\nyc = %lf\nteta = %lf\nxr = %lf\nyr = %lf\n",xc,yc,teta,xr,yr);
}
void rotate(double xc,double yc, double teta, double *xrPtr, double *yrPtr){
	*xrPtr=xc*cos(teta*M_PI/180)-yc*sin(teta*M_PI/180);
	*yrPtr=xc*sin(teta*M_PI/180)+yc*cos(teta*M_PI/180);
	
}
