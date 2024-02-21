/* Exercise 2-1 */

/* A program that determines the ranges of char, short, 
   int, and long variables, both signed and unsigned, by
   printing appropraite values from standard headers
   and by direct computation. 
*/

/* The program assumes that the integral types uses 
   2's complement number system. 
*/

#include <stdio.h>

#include <limits.h>
#include <float.h>

int main()
{
    printf("Print from header files: \n"); 
    printf("signed char\tmin:%d\tmax:%d\n", SCHAR_MIN, SCHAR_MAX); 
    printf("unsigned char\tmin:%d\tmax:%d\n", 0, UCHAR_MAX); 
    printf("signed short\tmin:%d\tmax:%d\n", SHRT_MIN, SHRT_MAX); 
    printf("unsigned short\tmin:%d\tmax:%d\n", 0, USHRT_MAX); 
    printf("signed int\tmin:%d\tmax:%d\n", INT_MIN, INT_MAX); 
    printf("unsigned int\tmin:%u\tmax:%u\n", 0, UINT_MAX); 
    printf("signed long\tmin:%ld\tmax:%ld\n", LONG_MIN, LONG_MAX); 
    printf("unsigned long\tmin:%lu\tmax:%lu\n", 0l, ULONG_MAX); 

    printf("Calculated: \n"); 
    /* compute the range of signed char */
    char cmin, cmax; 
    cmin = cmax = 0; 
    for (int i = 0; i < sizeof(char) * CHAR_BIT - 1; ++i) {
	cmax += (1 << i); 
    } 
    cmin += 1 << (sizeof(char) * CHAR_BIT - 1);  
    printf("signed char\tmin:%d\tmax:%d\n", cmin, cmax); 

    /* compute the max of unsigned char */ 
    /* note there is no leading sign bit */
    unsigned char ucmax = 0;     
    for (int i = 0; i < sizeof(unsigned char) * CHAR_BIT; ++i) {
	ucmax += (1 << i); 
    }
    printf("unsigned char\tmin:%d\tmax:%d\n", 0, ucmax);

    /* compute the range of short */ 
    short smin, smax; 
    smin = smax = 0; 
    for (int i = 0; i < sizeof(short) * CHAR_BIT - 1; ++i) {
	smax += (1 << i); 
    }
    smin += 1 << (sizeof(short)* CHAR_BIT - 1); 
    printf("signed short\tmin:%d\tmax:%d\n", smin, smax);

    /* compute the range of unsigned short */
    /* note there is no leading sign bit */ 
    unsigned short usmax = 0;     
    for (int i = 0; i < sizeof(unsigned short) * CHAR_BIT; ++i) {
	usmax += (1 << i); 
    }
    printf("unsigned short\tmin:%d\tmax:%d\n", 0, usmax);

    /* compute the range of int */
    int imin, imax; 
    imin = imax = 0; 
    for (int i = 0; i < sizeof(int) * CHAR_BIT - 1; ++i) {
	imax += (1 << i); 
    } 
    imin += 1 << (sizeof(int) * CHAR_BIT - 1);  
    printf("signed int\tmin:%d\tmax:%d\n", imin, imax); 

    /* compute the range of unsigned int */
    /* note there is no leading sign bit */ 
    unsigned int uimax = 0;     
    for (int i = 0; i < sizeof(unsigned int) * CHAR_BIT; ++i) {
	uimax += (1 << i); 
    }
    printf("unsigned int\tmin:%u\tmax:%u\n", 0, uimax);

    /* compute the range of long */ 
    long lmin, lmax; 
    lmin = lmax = 0; 
    for (int i = 0; i < sizeof(long) * CHAR_BIT - 1; ++i) {
	lmax += (1l << i); 
    }
    lmin += 1l << (sizeof(long) * CHAR_BIT - 1); 
    printf("signed long\tmin:%ld\tmax:%ld\n", lmin, lmax);

    /* compute the range of unsigned long */
    /* note there is no leading sign bit */ 
    unsigned long ulmax = 0; 
    for (int i = 0; i < sizeof(unsigned long) * CHAR_BIT; ++i) {
	ulmax += (1l << i); 
    }
    printf("unsigned long\tmin:%lu\tmax:%lu\n", 0l, ulmax);
}
