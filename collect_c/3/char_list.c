/* c-examples by A.A.Shtanyuk */
/* char_list.c  - list of chars */

#include <stdio.h>
#include <stdlib.h>

typedef struct INFO * PINFO;

struct INFO
{
	char ch;
	int count;
	PINFO next;
};

 PINFO create(char ch)
{
	PINFO head;
	head=(PINFO)malloc(sizeof(struct INFO));
	head->ch=ch;
	head->count=1;
	head->next=NULL;
	return head;
}
void add(PINFO head,char ch)
{
	while(1) {
		if(head->ch==ch) {
			head->count++;
			return;
		}
		if(head->next)
		  head=head->next;
		else
			break;
	} 
	head->next=(PINFO)
		malloc(sizeof(struct INFO));
	head=head->next;
	head->ch=ch;
	head->count=1;
	head->next=NULL;
}
void printList(PINFO head)
{
	while(head) {
		printf("%c-%d\n",
			head->ch,
			head->count);
		head=head->next;
	}
}

int main(int argc,char **argv)
{
	PINFO head=NULL;
	FILE *in;
	int ch;
	if(argc<2) {
		purs("Usage: char_list file.txt");
		return 1;
	}
	in=fopen(argv[1],"rt");
	if(!in) {
		perror("Error: ");
		exit(1);
	}
	if((ch=fgetc(in))!=EOF)
	{
		head=create((char)ch);
		while((ch=fgetc(in))!=EOF)
			add(head,(char)ch);
	}
	fclose(in);
	printList(head);

	return 0;
}
