#include<stdio.h>
 
int main()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int i,data,found = 0;
    printf("Enter search element ... \n");
    scanf("%d",&data);

    // search in the array with Linear search method
        //The time complexity here is 
        //best case : O(1)
        //worst case : O(n)
   for ( i = 0; i < 10; i++)
    {
        if (array[i]==data)
        {
            printf("element has found at index %d",i);
            found = 1;
            //break will close the loop if the data is found
            //it will take us to out of the loop
            break;
        }
        
    }

    //case 1 for not found condition
    if (found == 0)
    {
        printf("Data element not found in the Array\n");
    }

    //case 2 for not found condition
        if (i == 10)
    {
        printf("Data element not found in the Array\n");
    }

    return 0;
}