/*
C Programming powerUp -Page 147
Structure
2016-06-27
*/

#include<stdio.h>

typedef struct Books
{
	char name[100];
	char publisher[100];
	int price;
}book;


enum {SORT_TITLE,SORT_PUB,SORT_PRICE,EXIT};

int main(void) 
{
	int a = sizeof(book);
	printf("a : %d \n",a);

	return 0;
}
