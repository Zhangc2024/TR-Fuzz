 /* 
  * function signature for main:
 *
 *      main(int argc, char *argv[]);
 *
 * argc: argument count is the number of cmd_line args the program was invoked
 *       with
 * argv: argument vector is a pointer to an array of character strings that
 *       contain arguments, one per string
 *
 *
 * Simplest example:
 *      $ echo hello, world
 *
 * by convention, argv[0] is the name by which the program was invoked,
 * so argc is at least 1.
 * If argc is 1, there are no cmd-line args after the program name.
 *
 * in our echo example:
 *      argc is 3
 *      argv[0] is "echo"
 *      argv[1] is "hello,"
 *      argv[2] is "world
 *
 * the first optional argument is argv[1] and the last is argv[argc-1]
 *
 * Note: argv[argc] is a null pointer
 */

#include <stdio.h>
/* echo command-line arguments; 1st version */
main(int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; i++)
        printf("%s%s", argv[i], (i < argc-1) ? " ": "");
    printf("\n");
    return 0;
}
