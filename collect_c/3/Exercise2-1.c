#include<stdio.h>
#include<limits.h>
#include<float.h>

main (){
	 
	printf ("\nThe range of the value of *char* is: [%i to %i]\n\n", CHAR_MIN, CHAR_MAX );
	printf ("The range of the value of *short* is: [%i to %i]\n\n", SHRT_MIN, SHRT_MAX);
	printf ("The range of the value of *int* is: [%i to %i]\n\n", INT_MIN, INT_MAX);
	printf ("The range of the value of *long* is: [%i to %i]\n\n", LONG_MIN, LONG_MAX);
	printf ("The range of the value of *signed char* is: [%i to %i]\n\n", SCHAR_MIN, SCHAR_MAX);
	printf ("The maximum of the value of *unsigned char* is: [%i]\n\n", UCHAR_MAX);
	printf ("The maximum of the value of *unsigned short* is: [%i]\n\n", USHRT_MAX);
	printf ("The maximum of the value of *unsigned int* is: [%d]\n\n", 65536, UINT_MAX);
	printf ("The maximum of the value of *unsigned long* is: [%u]\n", ULONG_MAX);
	
}
