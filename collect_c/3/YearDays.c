/* Exercise 5-8 and Exercise 5-9 */ 
#include <stdio.h>

int day_of_year(int year, int month, int day); 
void month_day(int year, int yearday, int *pmonth, int *pday); 

int main()
{
    int yday = day_of_year(2016, 4, 9); 
    printf("day: %d\n", yday); 

    int month, day; 
    month = day = 0; 
    month_day(2016, yday, &month, &day); 
    printf("Month: %d, day: %d \n", month, day); 

    yday = day_of_year(2016, 4, 32); 
    printf("day: %d\n", yday); 

    yday = day_of_year(2016, 4, -5); 
    printf("day: %d\n", yday); 

    month_day(2016, 369, &month, &day); 
    printf("Month: %d, day: %d \n", month, day); 

    month_day(2015,-1, &month, &day); 
    printf("Month: %d, day: %d \n", month, day); 
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
};

static int maxday[2] = {365, 366}; 

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap; 

    if (month <= 0 || day <= 0) {
	printf("Negative month or day entered. \t"
	       "Month: %d Day: %d \n", month, day); 
	return -1; 
    }
    
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0; 

    char (*days)[13] = daytab + leap; 
    
    if (day > *(*days + month)) {
	printf("Invalid day \'%d\' for month %d \n", day, month); 
	return -1; 
    }
    
    for (i = 1; i < month; i++) {
	day +=  *(*days + i); 
    }
    return day; 
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap; 
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0; 

    char (*days)[13] = daytab + leap; 

    if (yearday < 1 || yearday > *(maxday + leap)) {
	printf("Invalid yearday. For year %d, "
	       " yearday must be between 1 and %d\n", 
	       year, *(maxday + leap));  
	return; 
    }
    
    for (i = 1; yearday > *(*days + i); i++)
	yearday -= *(*days + i); 
    *pmonth = i; 
    *pday = yearday; 
}
