/*
 * Determine the ranges of char, short, int, and long variables,
 * both signed and unsigned, by printing appropriate values from
 * standard headers and by direct computation.
 *
 * Not implemented: floating-point types
 */

#include <limits.h>
#include <stdio.h>

int
main(void)
{
	printf("Datatype Range: From limit.h Header\n");
	printf("Datatype:\tMinimum Value\t\t->\tMaximum Value\n");
	printf("Signed char:\t%d\t\t\t->\t%d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Unsigned char:\t%d\t\t\t->\t%d\n", 0, UCHAR_MAX);
	printf("Signed short:\t%d\t\t\t->\t%d\n", SHRT_MIN, SHRT_MAX);
	printf("Unsigned short:\t%d\t\t\t->\t%d\n", 0, USHRT_MAX);
	printf("Signed int:\t%d\t\t->\t%d\n", INT_MIN, INT_MAX);
	printf("Unsigned int:\t%u\t\t\t->\t%u\n", 0, UINT_MAX);
	printf("Signed long:\t%ld\t->\t%ld\n", LONG_MIN, LONG_MAX);
	printf("Unsigned long:\t%d\t\t\t->\t%lu\n", 0, ULONG_MAX);
	printf("\n");

	printf("Datatype Range: Computed Values\n");
	printf("Datatype:\tMinimum Value\t\t->\tMaximum Value\n");
	printf("Signed char:\t%d\t\t\t->\t%d\n", -0x7f-1, 0x7f);
	printf("Unsigned char:\t%d\t\t\t->\t%d\n", 0, 0xff);
	printf("Signed short:\t%d\t\t\t->\t%d\n", -0x7fff-1, 0x7fff);
	printf("Unsigned short:\t%d\t\t\t->\t%d\n", 0, 0xffff);
	printf("Signed int:\t%d\t\t->\t%d\n", -0x7fffffff-1, 0x7fffffff);
	printf("Unsigned int:\t%u\t\t\t->\t%u\n", 0, 0xffffffff);
	printf("Signed long:\t%ld\t->\t%ld\n", LONG_MIN, LONG_MAX);
	printf("Unsigned long:\t%d\t\t\t->\t%lu\n", 0, ULONG_MAX);

	return (0);
}
