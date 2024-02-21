// C program to demonstrate an armstrong number
// between the given intervals using pow()

#include <math.h>
#include <stdio.h>
int main()
{

	int lower,upper, num, n, armstrong = 0, i, result;
	printf("enter limit value of lower and upper : ");
    scanf("%d",&lower);
    scanf("%d",&upper);
    // iterating the for loop using the given intervals
	for (i = lower; i <= upper; i++) {
		num = i;
		result = i;
		// finding the armstrong number
		while (num != 0) {
			n = num % 10;
			armstrong = armstrong + pow(n, 3);
			num = num / 10;
		}
		// if number is equal to the armstrong then it is a
		// armstrong number
		if (result == armstrong) {
			printf("%d\n", i);
		}
		armstrong = 0;
	}
	return 0;
}
