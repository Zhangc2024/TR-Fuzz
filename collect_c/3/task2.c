#include<stdio.h>
#include<stdlib.h>

void odd(int arr[],int n){
     for(int i=0;i<n;i++){
         if(arr[i]%2!=0){
               printf("%d\t",arr[i]);
          }
     }
}
void even(int arr[],int n){
     for(int i=0;i<n;i++){
         if(arr[i]%2==0){
               printf("%d\t",arr[i]);
          }
     }
}
void max_min_count_avg(int arr[],int n){
       int max=0,min=arr[0],count=n,sum=0;
       float avg;
      for(int i=0;i<n;i++){ 
          if(arr[i]>max){
                  max=arr[i];
           }
         }
        for(int i=0;i<n;i++){ 
            
            if(arr[i]<min){
                min=arr[i];
            }
         }
          for(int i=0;i<n;i++){ 
             sum+=arr[i];
             avg=sum/n;
           }
            printf("\nMAXIMUM=%d",max);
            printf("\nMINIMUM=%d",min);
            printf("\nCOUNT=%d",count);
            printf("\nAVERAGE=%0.3f",avg);
}
void prime(int arr[],int n){
    for(int i=0;i<n;i++){
       int count=0;
       for(int j=2;j<arr[i];j++){
           if(arr[i]%j==0){
               count=1;
               break;
           }

       }
          
        if(count==0){
            printf("%d\t",arr[i]);
        }
    }
}

void main(){
     int arr[50],n,ch;
     printf("Enter the number of elements\n");
     scanf("%d",&n);
     printf("Enter the integer elements into array\n");
     for(int i=0;i<n;i++){
           scanf("%d",&arr[i]);
     }
     while(1){

         printf("\nMENU\n");
         printf("\n=>1.Print odd numbers in the array");
         printf("\n=>2.Print even numbers int he array");
         printf("\n=>3.Print max,min,count,average of array elements");
         printf("\n=>4.Print prime numbers in the array");
         printf("\n=>5.Exit");
         printf("\nEnter your choice\n");
         scanf("%d",&ch);
         switch(ch){
               case 1:odd(arr,n);
                       break;
               case 2:even(arr,n);
                       break;
               case 3:max_min_count_avg(arr,n);
                       break;
               case 4:prime(arr,n);
                      break;
               case 5:exit(1);
                      break;
               default:printf("enter a valid choice");
         }
     }
}

                      
         
     
