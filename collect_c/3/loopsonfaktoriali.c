#include <stdio.h>
int main()
{
    int son1, son2, f;
    printf("Sonni kiriting: ");
    scanf("%d", &son2);
    
    for (son1=1; son1<=son2; son1++)
    {
        f*=son1;
    }
    printf("%d ning faktoriali %d", son2, f);

    return 0;
}
