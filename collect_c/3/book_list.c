/* c-examples by A.A.Shtanyuk */
/* book_list.c  - list of books */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


enum
{
	CREATE=1,
	ADD,
	PRINT,
	SEARCH,
	SAVE,
	QUIT
};

struct BOOK
{
	char title[30];
	char author[30];
	int pages;
};
struct ITEM
{
	struct BOOK *book;
	struct ITEM *next;
};

struct ITEM *createList(struct BOOK *book)
{
	struct ITEM *head=(struct ITEM*)malloc(sizeof(struct ITEM));
	head->book=book;
	head->next=NULL;
	return head;
}
void add(struct ITEM *head,struct BOOK *book)
{
	while(head->next)
		head=head->next;
	head->next=(struct ITEM*)malloc(sizeof(struct ITEM));
	head->next->book=book;
	head->next->next=NULL;
}
void printList(struct ITEM * head)
{
	while(head)
	{
		printf("Title: %s Author: %s Pages: %d\n",
			    head->book->title,
				head->book->author,
				head->book->pages);
		head=head->next;
	}
}
struct BOOK * makeBook()
{
	char buf[256];
	struct BOOK *book=(struct BOOK*)malloc(sizeof(struct BOOK));
	printf("Enter title:\n");
	fgets(book->title,sizeof(book->title),stdin);
	printf("Enter author:\n");
	fgets(book->author,sizeof(book->author),stdin);	
	printf("Enter pages number:\n");
	fgets(buf,256,stdin);
	book->pages=atoi(buf);
	return book;
}
void printBook(struct BOOK *book)
{
	printf("Title: %s Author: %s Pages: %d\n",
	    book->title,
		book->author,
		book->pages);
}

int searchAuthor(struct ITEM *head, char *nameA)
{
	int found=0;
	while(head)
	{
		if(strstr(head->book->author,nameA))
		{
			found++;
			printBook(head->book);
		}
		head=head->next;
	}
	return found;
}

void search(struct ITEM* head)
{
	char buf[256];
	printf("Enter search search string (author): ");
	fgets(buf,256,stdin);
	if(buf[strlen(buf)-1]=='\n')
		buf[strlen(buf)-1]=0;
	int found=searchAuthor(head,buf);
	if(found)
		printf("\n found:%d\n",found);
	else
		printf("No books found\n");
}

int printMenu()
{
	int choice;
	printf("\n\n1. Create list\n");
	printf("2. Add struct ITEM\n");
	printf("3. Print list\n");
	printf("4. Search by author\n");
	printf("5. Save to file\n");
	printf("6. Quit\n");
	printf("\nEnter choice: \n\n");
	choice=getchar();
	getchar(); // for "enter"
	return choice-'0';
}

int saveToFile(struct ITEM* head, char *filename)
{
    FILE *fout;
	fout=fopen(filename,"wb");
	if(!fout)
		return 0;
	while(head)
	{
	    fwrite(head->book,sizeof(struct BOOK),1,fout);
		head=head->next;
	}	
	fclose(fout);
	return 1;
}
int main()
{
    struct ITEM *head=NULL;
	while(1)
	{
		int choice=printMenu();
		switch(choice)
		{
		case CREATE:
			if(!head)
              head=createList(makeBook());
			else
				printf("List exists!\n");
			break;
		case ADD:
			if(head)
              add(head,makeBook());
			else
				printf("List not exists!\n");
			break;
		case PRINT:
			printList(head);
			break;
		case SEARCH:
			if(head)
			   search(head);
			else
				printf("List not exists!\n");
			break;
		case SAVE:
			if(saveToFile(head,"books.dat"))
				printf("Data saved\n");
			else
				printf("Data not saved\n");
			break;
		case QUIT:
			return 0;
	    }
	}
	return 0;
}




