#include<stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int i, leap;
    leap = (year%4 == 0 && year%100 != 0) || (year%400 == 0);
    char *p = daytab[leap];
    while (--month) {
        day += *(++p);
    }
    return day;
}
/* month_day: set month, day from day of year */
void month_day(int year, int yearday, 
                int *pmonth, int *pday) {
    int i, leap;
    leap = (year%4 == 0 && year%100 != 0 )|| (year%400 == 0);
    char *p = daytab[leap];
    while (yearday > *(++p)) {
        yearday -= *p;
    }
    *pmonth = p - daytab[leap];
    //*pmonth = p - *(daytab + leap);
    *pday = yearday;
}

int main() {
    int year_1 = 2008, month = 12, day = 3;
    int year_2 = 2023, yearday = 34;
    int pmonth, pday;
    printf("The day of year for year %d, month %d, and day %d is:" 
    "%d\n", year_1, month, day, day_of_year(year_1, month, day));

    month_day(year_2, yearday, &pmonth, &pday);
    printf("%d days of the year %d is month %d, day %d\n", yearday, \
            year_2, pmonth, pday);
}