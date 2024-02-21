// Sorting Methods : 
// 1. Bubble Sort
// We are sorting it in Ascending order
#include<stdio.h>
int PrintArray(int array[],int size){
    for (int i = 0; i < size; i++)
    {
        printf(" %d ",array[i]);
    }
}

int BubbleSort(int array[],int size){
    for (int i = 0; i < size-1; i++)
    {
        int flag = 0;
        printf("Pass - %d \n",i);
        for (int j = 0; j < size-1-i; j++)
        {
            if (array[j]>array[j+1])
            {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j]= temp;
                flag =1;
                printf("Swapped\n");
            }   
        }
        if (flag==0)
        {
            break;
        }
           
    }
}
int main()
{
    int array[10] ={2,67,45,36,2,90,63,999,05,72};
    int n = sizeof(array)/sizeof(array[0]);
    BubbleSort(array,n);
    printf("Sorted Array is : {");
    PrintArray(array,n);
    printf("}");
    return 0;
}