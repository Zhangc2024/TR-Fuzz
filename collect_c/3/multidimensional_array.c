#include<stdio.h>

int main(){
    // int array[7]={6,7,8,9,10,12,15};
    // printf("value at 2nd position is %d",array[1]);
    // int sum = array[1]+array[2];
    // printf("sum is %d",sum);
    int array[2][3][4]=
    {
        {{1,2,4,5},{2,3,6,8},{6,7,8,4}},
        {{1,2,4,5},{2,3,6,8},{6,7,8,4}}
    };
    
//priting all elements of a multidimensional array
int i,j,k;
for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
        for(int k=0;k<4;k++){
            printf("array[%d][%d][%d] = [%d]\n",i,j,k, array[i][j][k]);
        }
    }
};
    return 0;
    };