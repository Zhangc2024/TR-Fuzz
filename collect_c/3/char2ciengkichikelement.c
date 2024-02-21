#include <stdio.h>
int main()
{
    int array[10], i;
    printf("10 ta sonni kiriting: ");
    for (i=0; i<10; i++)
    {
        scanf("%d", &array[i]);
    }
    int max1=array[0], imax=0;
    for (i=1; i<10; i++)
    {
        if (array[i]<max1)
        {
            max1=array[i]; imax=i;
        }
    }
    printf("max1=%d va indeksi=%d\n", max1, imax);
    int temp=array[0];
    array[0]=array[imax];
    array[imax]=temp;
    int max2=array[1];
    for (i=2; i<10; i++)
    {
        if (array[i]<max2)
        {
            max2=array[i];
        }
    }
    printf("ikkinchi eng kichik elementi: %d\n", max2);
    return 0;
}