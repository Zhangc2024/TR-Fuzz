/*
 * Exercise: multi_array.c 
 *
 */

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{

    int month, day;
    int d_of_y = day_of_year(1988, 10, 30);
    
    printf("The day_of_year(1988, 10, 30) is %d\n", d_of_y);

    month_day(1988, d_of_y, &month, &day);

    printf("The month_day(1988, %d, &month, &day) is %d, %d\n",
           d_of_y, month, day);

    return 0;//return SUCCESS
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    
    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }

    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

    for (i = 1; yearday > daytab[leap][i]; i++)  {
        yearday -= daytab[leap][i];
    }

    *pmonth = i;
    *pday = yearday;
}
