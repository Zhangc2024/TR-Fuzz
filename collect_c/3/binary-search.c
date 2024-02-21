#include<stdio.h>



int BinarySearch(int array[], int data, int low, int high){
    while (low<=high)
    {
        //this will seprate the array in two parts
        int mid = (low + high)/2;
        //if the element is found at middile point it will return index will of middle point
        //The time complexity here is 
        //best case : O(1)
        //worst case : O(log n) 
        if (data == array[mid]){
            return mid;
        }
        else if (data > array[mid]){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
    
}
int main()
{
    int data;
    int array[10]= {1,2,3,4,5,6,7,8,9,10};
    // this will get the number of array elements
    int n = sizeof (array)/ sizeof (array[0]);
    printf("Enter the data value : \n");
    scanf("%d",&data);
    int output = BinarySearch(array,data,0,n-1);

    if (output == -1)
    {
        printf("The search not found !!\n");
    }

    else {
        printf("the element is found at index %d",output);
    }
    
    return 0;
}