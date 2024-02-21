#include<stdio.h>
#include<stdlib.h>
struct BST{
    int data; 
    struct BST * lchild,* rchild;
};
typedef struct BST * NODE;
NODE get_node(){
    NODE temp;
    temp=(NODE)malloc(sizeof(struct BST));
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}
//newnode->data should not be equal to the root->data..if equal it will be ignored..
void insert(NODE root,NODE newnode){
    if(newnode->data < root->data){
        if(root->lchild==NULL){
            root->lchild=newnode;
        }else{
            insert(root->lchild,newnode);
        }
    }
    if(newnode->data > root->data){
            if(root->rchild==NULL){
                root->rchild=newnode;
            }else{
                insert(root->rchild,newnode);
            }
    }
}
void search(NODE root,int key){
    NODE cur;
    if(root==NULL){
        printf("\nBST is empty");
    }
    cur=root;
    while(cur!=NULL){
        if(cur->data==key){
            printf("\nThe key element %d is present in the BST",key);
            return;

        }
        if(key<cur->data){
            cur=cur->lchild;
        }else{
            cur=cur->rchild;
        }
    }
    printf("\nThe key element %d is not found int he BST ",key);
}
void inorder(NODE root){
    if(root!=NULL){
        inorder(root->lchild);
        printf("%d\t",root->data);
        inorder(root->rchild);
    }
}
void preorder(NODE root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
void postorder(NODE root){
    if(root!=NULL){
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d\t",root->data);
    }
}
int main(){
    int ch,val,key,i,n;
    NODE root=NULL,newnode;
    while(1){
        printf("\n~~~BST MENU~~~\n");
        printf("\n1=>create the BST");
        printf("\n2=>BST trsversals");
        printf("\n3=>search");
        printf("\n4=>EXit");
        printf("enter your choice:\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("enter the NUmber of elements\n");
                    scanf("%d",&n);
                    for(i=1;i<=n;i++){
                        newnode=get_node();
                        printf("ENter the value:\n");
                        scanf("%d",&val);
                        newnode->data=val;
                        if(root==NULL){
                            root=newnode;
                        }else{
                            insert(root,newnode);
                        }
                    }
                    break;
            case 2:if(root==NULL){
                    printf("The tree is not created yet..\n");
                   }else{
                       printf("\nThe inorder traverasal is: ");
                       inorder(root);
                       printf("\nThe preorder traversal is: ");
                       preorder(root);
                       printf("\nThe postorder traversal is: ");
                       postorder(root);
                   }
                   break;
            case 3:printf("\nEnter the element to be searched");
                    scanf("%d",&key);
                    search(root,key);
                    break;

            case 4:exit(1);
                    break;
            default:printf("\nenter the valid choice");

            }
        
    }
    return 0;
}