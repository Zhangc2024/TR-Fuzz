#include <stdio.h>
#include <math.h>
double geoSeries (double x, double R, double N);
main(){
	double a,r,n;
	double sn;
	
	printf("Enter a, r and n values:");
	scanf("%lf%lf%lf",&a,&r,&n);
	
	sn=geoSeries(a,r,n);
	
	printf("Geometric Series is sn=%lf when a=%lf, r=%lf, n=%lf",sn,a,r,n);
	
	
}
double geoSeries (double x, double R, double N){
	double geo;
	geo=(x*(1-pow(R,N)))/(1-R);
	return geo;
}
