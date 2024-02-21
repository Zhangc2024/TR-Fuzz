#include <stdio.h>

#define name "Cameron"
#define hello printf("Hello\n");
#define say(number) printf("%d\n", number);

/**
 * Removes defined name
 */
#undef name

#define SYSTEM 1

#if SYSTEM == 1
    #define OS 1
#elif SYSTEM == 2
    #define OS 2
#endif

#ifndef HDR
    #define HDR 1
#endif

int main() {
    hello;
    say(65);

    /**
     * Will print 1
     */
    printf("%d\n", OS);
    return 0;
}
