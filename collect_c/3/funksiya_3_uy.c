#include <stdio.h>
int raqam(int son)
{
    if(son==0)
    { return 0; }
    if(son!=0)
    {
        return son%10+raqam(son/10);
    }
}
int main()
{
    int number;
    printf("Number: "); scanf("%i", &number);
    printf("Sonning raqamlari yig'indisi: %i\n", raqam(number));
    return 0;
}