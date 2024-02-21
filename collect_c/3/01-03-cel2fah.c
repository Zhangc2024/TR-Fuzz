/*** ÉãÊÏ¶È×ª»ªÊÏ ***/
#include <stdio.h>

main()
{
    float cels, fahr;
    int lower, upper, step;

    lower = 10;
    upper = 200;
    step = 10;

    cels = lower;

    printf ("cels\tfahr\n");
    while (cels <= upper)
    {
        fahr = cels * (9.0/5.0) + 32.0;
        printf("%6.2f\t%.2f\n", cels, fahr);

        cels = cels + 20;
    }
}
