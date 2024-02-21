#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{

    /* for char */

    printf("The min value of type char is %d\n", CHAR_MIN);
    printf("The max value of type char is %d\n", CHAR_MAX);
    printf("The min value of type signed char is %d\n", SCHAR_MIN);
    printf("The max value of type signed char is %d\n", SCHAR_MAX);
    printf("The max value of unsigned char is %d\n", UCHAR_MAX);

    /* for short */

    printf("The min value of type short is %d\n", SHRT_MIN);
    printf("The max value of type short is %d\n", SHRT_MAX);
    printf("The max value of type unsigned short is %d\n", USHRT_MAX);


    /* for int */

    printf("The min value of type int is %d\n", INT_MIN);
    printf("The max value of type int is %d\n", INT_MAX);
    printf("The max value ot type unsigned is %u\n", UINT_MAX);

    /* for long */
    printf("The min value of type long is %ld\n", LONG_MIN);
    printf("The max value of type long is %ld\n", LONG_MAX);
    printf("The max value of type unsigned long is %lu\n", ULONG_MAX);

    /* for long long */
    printf("The min value of type long long is %lld\n", LLONG_MIN);
    printf("The max value of type long long is %lld\n", LLONG_MAX);
    printf("The max value of type unsigned long long is %llu\n", ULLONG_MAX);

    /* for floating-point types */
    printf("The min value of positive floating-point number is %f\n", FLT_MIN);
    printf("The max value of finite floating-point number is %f\n", FLT_MAX);
    

    return 0;
}
