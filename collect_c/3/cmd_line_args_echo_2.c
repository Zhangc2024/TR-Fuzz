/*
 * since argv is a pointer to an array of pointers, we can manipulate the
 * pointer rather than index the array.
 * this version is based on incrementing argv, which is a pointer to pointer
 * to char, while argc is counted down
 */

#include <stdio.h>
/* echo command-line arguments; 2nd version */
main(int argc, char *argv[]) {
    while (--argc > 0)
        printf((argc > 1) ? "%s ": "%s", *++argv);
    printf("\n");
    return 0;
}

/* since argv is a pointer to the beginning of the array of arguments strings,
 * incrementing it by 1 (++argv) makes it point at the original argv[1] instead
 * of argv[0]. Each successive increment moves it along to the next arg
 *
 * - note: we changed the argument to printf. orginal was
 *      printf("%s%s", *++argv, (argc > 1) ? " ": "");
 */
