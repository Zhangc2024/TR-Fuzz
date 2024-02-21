#include <stdio.h>
/* consider the problem of date conversion, from day of the month
 * to day of the year and vice versa.
 * E.g. March 1 is the 60th day of a non-leap year, and the 61st day of a leap
 * year.
 *
 * Let's define two functions to do the conversation: day_of_year converts the
 * month and day into the day of the year, and month_day converts the day of
 * the year into the month and day.
 *
 * Since the latter function computes two values, the month and day arguments
 * will be pointers
 *
 * month_day(1988, 60, &m, &d)
 */

/* - daytab is of type char to illustrate a legitimate use of char for storing
 *   small non-character integers
 *
 * - In C, a 2D array is really a 1D array, each of whose elements is an array
 *   hence the subsripts are written as
 *      daytab[i][j]
 *   which is
 *      daytab[row][col]
 *
 * - We start the array daytab with a column of zero so that the month numbers
 *   can run from the natural 1 to 12. Since space is not a premium here, this
 *   is clearer than adjusting the indices.
 */
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

/* note: arithmetic value of a logical expression such as the one for leap
 * is either zero (false) or one (true) so it can be used as a usbscript for
 * array daytab
 */

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/*month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}

int main() {
    return 0;
}
