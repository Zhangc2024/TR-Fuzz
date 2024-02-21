// Authored by - unsuitable001
// reference : http://people.math.sc.edu/girardi/m142/handouts/10sTaylorPolySeries.pdf - page 1
#include<stdio.h>
#define PI 3.141
int factorial(int x){   //simple factorial function using while loop. need this as a helper function
    int i = x;
    while(i > 1){
        x = x*(--i);    //decresing the value of "i" by using pre-decrement shorthand
    }
    if(x==0){
        return 1;       //returning 1 if the input is 0.
                        //no else part is needed as the return statement exits the function
    }
    return x;
}
double power(double x, double y){	// need this as a helper function
	if(y == 0){
		return 1.0;
	}
	double z = x;
	while(y > 1){
		x = x*z;
		y--;
	}
	return x;
}
double sine(double x){
    double p = 6.0;			//set the precision factor
	int n = 0;
	double res = 0.0;
	while(p>n){
		res = res + (power(-1,n)*(power(x,(2*n)+1)/factorial((2*n)+1)));	//Taylor's sine series - refer link
		n++;
	}
	return res;
}
double cosine(double x){
	double p = 6.0;			//set the precision factor
	int n = 0;
	double res = 0.0;
	while(p>n){
		res = res + (power(-1,n)*(power(x,2*n)/factorial(2*n)));		//Taylor's cosine series - refer link
		n++;
	}
	return res;
}
double tangent(double x){
    return sine(x)/cosine(x);
}
double cosecant(double x){
    return 1.0/sine(x);
}
double secant(double x){
    return 1.0/cosine(x);
}
double cotangent(double x){
    return cosine(x)/sine(x);
}
int main(){
	double a,factor;
    int opt,mode;
    printf("I want to get \n\n(0)SIN \n (1)COS \n:");
    scanf("%d",&opt);
    printf("Give me number :");
    scanf("%lf",&a);
    printf("MODE : \n (0)RAD \n (1)DEG \n :");
    scanf("%d",&mode);
	switch (mode)
	{
		case 0:
			break;
		case 1:
			factor = PI/180;
			a = a * factor;
		default:
			break;
	}
    switch (opt)
    {
        case 0:
            printf("%.10lf",sine(a));
            break;
        case 1:
            // printf("%.10lf",sine((PI/2) - a*factor));
			printf("%.10lf",cosine(a));
            break;
        default:
            break;
    }
    return 0;
}