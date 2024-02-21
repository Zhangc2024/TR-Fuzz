#include<stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int i, leap;
    leap = (year%4 == 0 && year%100 != 0) || (year%400 == 0);
    if (year < 1) {
        return -1;
    }
    if (month < 1 || month > 12) {
        return -1;
    }
    if (day < 1 || day > daytab[leap][month]) {
        return -1;
    }
    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }
    return day;
}
/* month_day: set month, day from day of year */
void month_day(int year, int yearday, 
                int *pmonth, int *pday) {
    if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    int i, leap;
    leap = (year%4 == 0 && year%100 != 0 ) || (year%400 == 0);
    for (i = 1; yearday > daytab[leap][i] && i <= 12; i++) {
        yearday -= daytab[leap][i];
    }
    if (i > 12) {
        *pmonth = -1;
        *pday = -1;
    } else {
        *pmonth = i;
        *pday = yearday;
    }
}

int main() {
    int year_1 = 2008, month_1 = 12, day_1 = 3;
    int year_2 = 2008, month_2 = 13, day_2 = 3;
    int year_3 = 2008, month_3 = 11, day_3 = 35;
    printf("The day of year for year %d, month %d, and day %d is:" 
    "%d\n", year_1, month_1, day_1, day_of_year(year_1, month_1, day_1));
    printf("The day of year for year %d, month %d, and day %d is:" 
    "%d\n", year_2, month_2, day_2, day_of_year(year_2, month_2, day_2));
    printf("The day of year for year %d, month %d, and day %d is:" 
    "%d\n", year_3, month_3, day_3, day_of_year(year_3, month_3, day_3));

    int year_4 = 2023, yearday_1 = 34;
    int pmonth_1, pday_1;
    int year_5 = 2022, yearday_2 = 370;
    int pmonth_2, pday_2;
    month_day(year_4, yearday_1, &pmonth_1, &pday_1);
    printf("%d days of the year %d is month %d , day %d\n", yearday_1, \
            year_4, pmonth_1, pday_1);
    month_day(year_5, yearday_2, &pmonth_2, &pday_2);
    printf("%d days of the year %d is month %d , day %d\n", yearday_2, \
            year_5, pmonth_2, pday_2);
}