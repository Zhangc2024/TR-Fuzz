#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *sonlar;
    int n;
    printf("n="); scanf("%i", &n);
    // sonlar = malloc(n*sizeof(int)); //xotiradan seriya uchun joy ajratish
    sonlar = calloc(n, sizeof(int)); //xotiradan seriya uchun joy ajratish
    for (int i=0; i<n; i++)
    {
        scanf("%i", &sonlar[i]);
    }
    /* sonlar = realloc(sonlar, n+5); //dynamic seriya uchun ajratilgan joyni 5 taga uzaytirish
    for (int i=n; i<n+5; i++)
    {
        scanf("%i", &sonlar[i]);
    }
    n=n+5; */
    printf("Seriyadagi sonlar: ");
    for (int i=0; i<n; i++)
    {
        scanf("%i ", &sonlar[i]);
    }
    puts("");
    free(sonlar);
    return 0;
}