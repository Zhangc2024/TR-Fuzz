// perform addition operation upon two structures

#include <stdio.h>

struct measure {
	int inch;
	float feet;
} d1, d2, sum;

int main()
{
	printf("Please enter inch and feet of first measurement: ");
	scanf("%d %f", &d1.inch, &d1.feet);

	printf("Please enter inch and feet of second measurement: ");
	scanf("%d %f", &d2.inch, &d2.feet);

	sum.inch = d1.inch + d2.inch;
	sum.feet = d1.feet + d2.feet + (sum.inch % 12) / 12.00;
	sum.inch -= sum.inch % 12;

	printf("total measurement: %d inches and %f feet.\n", sum.inch, sum.feet);

	return 0;
}
