/* c-examples by A.A.Shtanyuk */
/* word_tree.c  - binary tree of words (strings) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

struct NODE
{
	int count;
	char word[SIZE];
	struct NODE *left;
	struct NODE *right;
};

struct NODE * addTree(struct NODE *root,char *word)
{
	if(root==NULL)
	{
		struct NODE *temp=(struct NODE*)malloc(sizeof(struct NODE));
		temp->count=1;
		strcpy(temp->word,word);
		temp->left=temp->right=NULL;
		return temp;
	}
	else if(strcmp(root->word,word)>0)
	{
		root->left=addTree(root->left,word);
		return root;
	}
	else if(strcmp(root->word,word)<0)
	{
		root->right=addTree(root->right,word);
		return root;
	}
	else
	{
		root->count++;
		return root;
	}
}

void printTree(struct NODE *root)
{
	if(root)
	{
		if(root->left)
			printTree(root->left);
		printf("%s - %d\n",root->word,root->count);
		if(root->right)
			printTree(root->right);
	}
}

int main(int argc, char *argv[])
{
	struct NODE *root=NULL;
	FILE *fp=fopen(argv[1],"rt");

	char buf[SIZE];
	while(!feof(fp))
	{
		fscanf(fp,"%s",buf);
		root=addTree(root,buf);
	}
	printTree(root);
	return 0;
}




	
