#include <stdio.h>

/* determine range of types */
main()
{
    /* signed types */
    printf("signed char min = %d\n",
           -(char)((unsigned char)~0 >> 1));
    printf("signed char max = %d\n",
           (char)((unsigned char)~0 >> 1));

    printf("signed short min = %d\n",
           -(short)((unsigned short)~0 >> 1));
    printf("signed short max = %d\n",
           (short)((unsigned short)~0 >> 1));
    printf("signed int min = %d\n",
           -(short)((unsigned int)~0 >> 1));
    printf("signed int max = %d\n",
           (short)((unsigned int)~0 >> 1));
    printf("signed long min = %d\n",
           -(long)((unsigned int)~0 >> 1));
    printf("signed long max = %ld\n",
           (long)((unsigned int)~0 >> 1));

    /* unsigned type */
    printf("unsigned char max = %u\n",
           (unsigned char)~0);

    printf("unsigned short max = %u\n",
           (unsigned short)~0);
    printf("unsigned int max = %u\n",
           (unsigned int)~0);
    printf("unsigned long max = %u\n",
           (unsigned long)~0);
}
