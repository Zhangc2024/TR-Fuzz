#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr,*rev_arr, i,j;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    rev_arr=(int*) malloc(num* sizeof(int));
    for(i = 0; i < num; i++) 
    {
        scanf("%d", arr + i);
    }
    for(i=num-1,j=0;i>=0&&j<num;i--,j++)
    {
        *(rev_arr+j)=*(arr+i);
    }

    /* Write the logic to reverse the array. */

    for(i = 0; i < num; i++)
    {
        *(arr+i)=*(rev_arr+i);
        printf("%d ", *(arr + i));
    }   
    return 0;
}
