/* c-examples by A.A.Shtanyuk */
/* list.c  - a simple linked list with numbers */

#include <stdio.h>
#include <stdlib.h>

struct ITEM
{
	int value;
	struct ITEM *next;
};

struct ITEM *create(int value)
{
	struct ITEM *head=(struct ITEM*)malloc(sizeof(struct ITEM));
	head->value=value;
	head->next=NULL;
	return head;
}

void addItem(struct ITEM* head,int value)
{
	while(head->next)
		head=head->next;
	head->next=(struct ITEM*)malloc(sizeof(struct ITEM));
	head->next->value=value;
	head->next->next=NULL;
}

void print(struct ITEM* head)
{
	while(head->next)
	{
		printf("%d ",head->value);
		head=head->next;
	}
	printf("%d ",head->value);
}

int main()
{
	struct ITEM *head=NULL;
	int number,i;
	for(i=0;i<10;i++)
	{
		scanf("%d",&number);
		if(i==0)
			head=create(number);
		else
			addItem(head,number);
	}
	print(head);
	putchar('\n');
	return 0;
}
			

