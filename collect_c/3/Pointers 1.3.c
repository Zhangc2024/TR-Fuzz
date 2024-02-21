#include <stdio.h>
#include <math.h>
void Calculation(double a,double b,double c,double *tPtr,double *fPtr);
main(){
	double a,b,c;
	
	printf("Enter value for a , b and c:\n");
	scanf("%lf%lf%lf",&a,&b,&c);
	double teta,fi;
	
	Calculation(a,b,c,&teta,&fi); 
	printf("\n");
	printf("a = %lf\n",a);
	printf("b = %lf\n",b);
	printf("c = %lf\n",c);
	printf("teta = %lf\n",teta);
	printf("fi = %lf\n",fi);
	
	
}
void Calculation(double a,double b,double c,double *tPtr,double *fPtr){
	*tPtr=acos(-(a*a-b*b-c*c)/(2*b*c));
	*fPtr=asin(sin(40*M_PI/180)*b/c);
	
	
}
