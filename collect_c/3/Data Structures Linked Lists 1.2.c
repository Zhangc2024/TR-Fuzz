#include<stdio.h>
#include<stdlib.h>

// structure definition
// self-referential structure 
typedef struct listNode {
	int data;  // each listNode contains an
	struct listNode *nextPtr;  // pointer to next node
} Node;

// initially there are no nodes
// So that startPtr points nothing;
Node *startPtr=NULL;

// function prototypes
int isEmpty(void);
void push_back(int value);
void push_front(int value);
void insert(int position,int value);
void printList(void);
void pop_back(void);
void pop_front(void);
void erase(int position);
void clear(void);
int size(void);


int main(void)
{
	int i;
	
	for(i=0;i<25;i++)
		push_back(rand()%5);
	printList();		
	
	Node *currentPtr=startPtr;
	int freq[5]={},dummy;
	while(currentPtr!=NULL){
		dummy=currentPtr->data;
		switch(dummy){
			case 0:
				freq[0]++;
			break;	
			case 1:
				freq[1]++;
			break;	
			case 2:
				freq[2]++;
			break;	
			case 3:
				freq[3]++;
			break;	
			case 4:
				freq[4]++;	
			break;				
		}
		currentPtr=currentPtr->nextPtr;
	}
	clear();
	for(i=0;i<5;i++)
		push_back(freq[i]);
	printList();
	int max=0,index=-1;
	currentPtr=startPtr;
	for(i=0;i<size();i++){
		dummy=currentPtr->data;
		if(dummy>max){
			max=dummy;
			index=i;
		}
		currentPtr=currentPtr->nextPtr;
	}
	printf("\nMaximum is %d and its index is %d\n",max,index);
	
}

// return 1 if the list is empty, 0 otherwise
int isEmpty(void)
{
	if (startPtr==NULL)
		return 1;
	else
		return 0;
}

// add the value at the end of the list
void push_back(int value)
{
	
	// Local variable to iterate the list
	Node *currentPtr;
	
	if (isEmpty()){  // Case 1: If the list is empty
	
		Node *newNode=malloc(sizeof(Node)); // create node;
		newNode->data=value;
		newNode->nextPtr=NULL;
		
		startPtr=newNode;
		printf("push back first item %d\n",value);
		
	}
	else{  // Case 2: If the list is not empty

		currentPtr=startPtr;
		Node *newNode=malloc(sizeof(Node)); // create node;
		newNode->data=value;
		newNode->nextPtr=NULL;
		
		while(currentPtr->nextPtr!=NULL)
			currentPtr=currentPtr->nextPtr;
		
		currentPtr->nextPtr=newNode;
		printf("push back %d\n",value);
	}
}

// add the value at the beginning of the list
void push_front(int value)
{
	// Local variable to iterate the list
	Node *currentPtr;

	if (isEmpty()){  // Case 1: If the list is empty
	
		Node *newNode=malloc(sizeof(Node)); // create node;
		newNode->data=value;
		newNode->nextPtr=NULL;
		
		startPtr=newNode;
		printf("push front first item %d\n",value);
	}
	else{  // Case 2: If the list is not empty
		
		currentPtr=startPtr;
		
		Node *newNode=malloc(sizeof(Node)); // create node;
		newNode->data=value;
		newNode->nextPtr=currentPtr;

		startPtr=newNode;
		printf("push front %d \n",value);
	}
}

// add the value at desired position
void insert(int position,int value)
{
	int count=1;
	// Local variables to iterate the list
	Node *previousPtr=NULL;
	Node *currentPtr=startPtr;
	
	while(count<position){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
		count++;
	}
	
	Node *newNode=malloc(sizeof(Node)); // create node;
	newNode->data=value;
	newNode->nextPtr=currentPtr;

	previousPtr->nextPtr=newNode;
	printf("insert %d to position %d\n",value,position);
}

// print the list
void printList(void)
{
	
	Node *currentPtr=startPtr;
	if (startPtr==NULL)
		printf("The list is empty\n");
	else{

		printf("The list is:\n");
		while(currentPtr!=NULL){
			printf("%3d---->",currentPtr->data);
			currentPtr=currentPtr->nextPtr;
		}
		printf("\n");
	}
}

// delete the item at the end of the list 
void pop_back(void)
{
	// Local variables to iterate the list
	Node *previousPtr=NULL;
	Node *currentPtr=startPtr;

	if (isEmpty())  // Case 1: If the list is empty
		printf("The list is empty.\nThere is no item to delete");
	else{  // Case 2: If the list is not empty

		while(currentPtr->nextPtr!=NULL){
			previousPtr=currentPtr;
			currentPtr=currentPtr->nextPtr;
		}
		
		previousPtr->nextPtr=NULL;
		free(currentPtr);
		printf("pop back is done\n");
	}
}

// delete the item at the beginning of the list
void pop_front(void)
{
	// Local variables to iterate the list
	Node *currentPtr;

	if (isEmpty())  // Case 1: If the list is empty
		printf("The list is empty.\nThere is no item to delete");
	else{  // Case 2: If the list is not empty

		currentPtr=startPtr->nextPtr;
		free(startPtr);
		startPtr=currentPtr;
		
		printf("pop front is done\n");
	}
}

// delete the value at desired position
void erase(int position)
{
	int count=1;
	// Local variables to iterate the list
	Node *previousPtr=NULL;
	Node *currentPtr=startPtr;

	while(count<position){
		previousPtr=currentPtr;
		currentPtr=currentPtr->nextPtr;
		count++;
	}
	
	previousPtr->nextPtr=currentPtr->nextPtr;
	free(currentPtr);
	printf("erase the item that placed at position %d\n",position);
}

// clear the list
void clear(void)
{
	// delete the first item until the list becomes empty
	while(!isEmpty())
		pop_front();
}

// returns the size of the list
int size(void)
{
	int count=0;
	Node *currentPtr=startPtr;

	//If the list is empty
	if (startPtr==NULL)
		return 0;
	else{
		
		while(currentPtr!=NULL){
			currentPtr=currentPtr->nextPtr;
			count++;
		}
		
		return count;
	}
} 
