/*
C Programming powerUp -Page 97
Parameter Array
2016-06-26
*/

#include <stdio.h>

int sumA(int* arr, int size) 
{
	int sum = 0,i;
	for (i = 0; i < size; i++) sum += arr[i];
	return sum;
}

void sum2A(int(*arr)[6]) 
{
	int i, sum = 0;
	for (i = 0; i < 4; i++) sum += arr[0][i];
	printf("1번째 줄의 합 %d \n", sum);

	for (i = 0, sum=0; i < 6; i++) sum += arr[1][i];
	printf("2번째 줄의 합 %d \n", sum);
}


int main(void) 
{
	int sum;
	int arr[3] = { 5,10,15 };
	int arr2[2][6] = { {1,3,5,7},{1,2,3,4,5,6}};
	sum = sumA(arr, 3);
	printf("1차원 배열의 합 : %d \n", sum);
	sum2A(arr2);



	return 0;
}