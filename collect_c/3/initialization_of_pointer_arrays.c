/* consider writing a function month_name(n), which returns a pointer to a 
 * character string containing the n-th month.
 */

/* month_name: return name of n-th month */
char *month_name(int n) {
    static char *name[] = {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    return (n < 1 || n > 12) ? name[0]: name[n];
}
