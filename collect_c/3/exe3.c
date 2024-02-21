#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char matn[]="Men Foundation#32 a'zosiman. Hammaga alangalik salom!";
    int =0, i;
    for (i=0; i<strlen(matn); i++)
    {
        if (isalpha(matn[i]))
        { harf++; }
    }
    printf("Kiritilgan matnda %d ta harf bor.\n");
    return 0;
}