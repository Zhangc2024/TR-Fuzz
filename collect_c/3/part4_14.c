/*
C Programming powerUp -Page 61
Bubble sort
2016-06-26
*/

#include<stdio.h>
#define ARR_LEN 5

int main(void)
{
	int data[ARR_LEN], i,j,temp;

	for (i = 0; i < 5; i++) scanf("%d", data+i);


	for (i = 0; i < 5; i++) {
		for (j = 0; j < ARR_LEN - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 5; i++) printf("%d ",data[i]);
	puts("");

}