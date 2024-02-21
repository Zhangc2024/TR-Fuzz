#include <stdio.h>
#include <math.h>
void response (double r,double c, double v0, double t, double *vtPtr);
main(){
	double R,C,V0,t,vt;
	vt=0;
	printf("Enter R, C and V0\n");
	scanf("%lf%lf%lf",&R,&C,&V0);	
	for(t=10;t<=50;t+=10){
		response(R,C,V0,t,&vt);
		printf("When t = %lf, vt =%lf\n",t,vt);

	}
		
	
}
void response (double r,double c, double v0, double t, double *vtPtr){
	*vtPtr=v0*exp((-t)/(r*c));
}
