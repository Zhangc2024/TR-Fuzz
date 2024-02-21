/* c-examples by A.A.Shtanyuk */
/* char_tree.c  - binary tree of chars */

#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	char symb;
	int count;
	struct NODE *left;
	struct NODE *right;
};

typedef struct NODE* PNODE;

PNODE addNode(PNODE root,char symb)
{
	if(root==NULL)	{
		root=(PNODE)malloc(sizeof(struct NODE));
		root->symb=symb;
		root->count=1;
		root->left=NULL;
		root->right=NULL;
	}
	else if(root->symb>symb)
		root->left=addNode(root->left,symb);
	else if(root->symb<symb)
		root->right=addNode(root->right,symb);
	else
		root->count++;
	return root;
}
void printTree(PNODE root)
{
	if(root)
	{
		printTree(root->left);
		printf("%c(%d)\n",root->symb,root->count);
		printTree(root->right);
	}
}
int main()
{
	PNODE root=NULL;
	char ch;
	int i;

	for(i=0;i<10;i++)
	{
		printf("Enter a char: ");
		scanf("%c",&ch);
		root=addNode(root,ch);
	}
	printTree(root);
	return 0;
}
