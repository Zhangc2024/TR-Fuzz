//6-masala
#include <stdio.h>

int main()
{
    int son,sikl;
    printf("son="); scanf("%d",&son);
    printf("sikl="); scanf("%d",&sikl);
    int c = 1,d,sum = 0;
    for(int i=0;i<sikl;i++)
	{
        d = c*son;
        sum+=d;
        printf("%d",d);
        c = c*10+1;
        if(i!=sikl-1)
		{
            printf("+");
        }
        else if(i==sikl-1)
		{
            printf("=");
        }
    }
    printf("%d",sum);
    return 0;
}
