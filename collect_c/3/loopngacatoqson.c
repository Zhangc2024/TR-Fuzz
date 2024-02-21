
#include <stdio.h>

int main()
{
    int i, n;
  
    printf("Chegara sonni kiriting: ");
    scanf("%d", &n);

    printf("%d gacha bo'lgan toq sonlar: \n", n);

    for(i=n; i>=1; i--)
    {
     
        if(i %2!= 0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}
