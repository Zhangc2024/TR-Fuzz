/* c-examples by A.A.Shtanyuk */
/* event_list.c  - a linked list example */

#include <stdio.h>
#include <stdlib.h>

typedef struct EVENT * PEVENT;
typedef struct ITEM* PITEM;

struct EVENT
{
	int day;
	char mon[20];
	char text[50];
};
struct ITEM
{
	PEVENT event;
	PITEM next;
};

PEVENT newEvent()
{
	
	PEVENT ptr;
	ptr=(PEVENT)
		malloc(sizeof(struct EVENT));
	printf("Enter day: ");
	scanf("%d",&ptr->day);
	printf("Enter month: ");
	scanf("%s",ptr->mon);
	printf("Enter event: ");
	scanf("%s",ptr->text);
	return ptr;
}

 PITEM create(PEVENT event)
{
	PITEM head;
	head=(PITEM)malloc(sizeof(struct ITEM));
	head->event=event;
	head->next=NULL;
	return head;
}
void add(PITEM head,PEVENT event)
{
	while(head->next)
		head=head->next;

	head->next=(PITEM)
		malloc(sizeof(struct ITEM));
	head=head->next;
	head->event=event;
	head->next=NULL;
}
void printList(PITEM head)
{
	while(head) {
		printf("%d-%s-%s\n",
			head->event->day,
			head->event->mon,
			head->event->text);
		head=head->next;
	}
}

int main()
{
	PITEM head;
	head=create(newEvent());
	// some events...
	add(head,newEvent());
	add(head,newEvent());
	add(head,newEvent());
	add(head,newEvent());
	printList(head);
	return 0;
}
