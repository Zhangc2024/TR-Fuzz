# include <stdio.h>

/* determine ranges of types */
main(){
    /* signed types */
    printf("signed char min = %d\n", -(char)((unsigned char)~0 >> 1));
    printf("signed char max = %d\n",(char)((unsigned char)~0 >> 1));
    printf("signed short min = %d\n", -(short)((unsigned short) ~0 >> 1));
    printf("signed short max = %d\n", (short)((unsigned short) ~0 >> 1));
    printf("signed int min = %d\n", -(int)((unsigned int) ~0 >> 1));
    printf("signed int max = %d\n", (int)((unsigned int) ~0 >> 1));
    printf("signed long min = %1d\n", -(long)((unsigned long) ~0 >> 1));
    printf("signed long max = %1d\n", (long)((unsigned long) ~0 >> 1));
    /* unsigned types */
    printf("unsigned char max = %u\n",(unsigned char) ~0);
    printf("unsigned short max = %u\n", (unsigned short) ~0);
    printf("unsigned int max = %u\n", (unsigned int) ~0);
    printf("unsigned long max = %1u\n",(unsigned long) ~0);
}
