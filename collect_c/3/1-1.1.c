#include <stdio.h>
#include<math.h>
main(){
double b,a,c,delta,x1,x2;

printf("Enter value for a, b and c:\n");
scanf("%lf%lf%lf",&a,&b,&c);
printf("Our Equation is equal to:\n%lf*x*x + %lf*x + %lf = 0\n",a,b,c);
delta=pow(b,2)-4*a*c;

if(delta>0)
	printf("There are 2 real roots and delta is equalt to %lf\n",delta);
else if (delta==0)
	printf("There is 1 real roots and delta is equalt to %lf\n",delta);
else
	printf("There are 2 complex roots and delta is equalt to %lf\n",delta);	
	
x1=(b+sqrt(delta))/(2*a);	
x2=(b+sqrt(delta))/(2*a);
	if(delta==0)
		printf("This equation's root is %lf",x1);
	else if(delta>0){
		printf("This equation's root are x1=%lf\tx2=%lf",x1,x2);
	}		
	else{
		printf("There are 2 complex roots and complex root x1 equal to (%lf+i%lf)\n",b/(2*a),sqrt(fabs(delta))/2*a);
		printf("There are 2 complex roots and complex root x2 equal to (%lf-i%lf)\n",b/(2*a),sqrt(fabs(delta))/2*a);		
	}
	
	
}
