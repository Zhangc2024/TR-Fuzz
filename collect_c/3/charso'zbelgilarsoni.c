#include <stdlib.h>
int main()
{
    char text[]="Abdullayev Abdulla Abdullayevich";
    int size=0, i;
    for (i=0; text[i]!='\0'; i++)
    {
        printf("%c", text[i]);
        ++size;
    }
    printf("\nKiritilgan belgilar soni: %d ta\n", size);
    return 0;
}