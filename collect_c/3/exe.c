#include <stdio.h>
int main()
{
    char matn[]="Bugun havo yaxshi";
    int i;
    for (i=0; matn[i]!='\0'; i++)
    { matn[i+1]==' ' && matn[i]=='\0'; }
    printf("%s\n", matn);
    return 0;
}