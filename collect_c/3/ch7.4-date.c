#include <stdio.h>

main()
{
    int day, year;
    char monthname[20];

    scanf("%d%s%d", &day, monthname, &year);
    printf("%d %s %d", day, monthname, year);
}
