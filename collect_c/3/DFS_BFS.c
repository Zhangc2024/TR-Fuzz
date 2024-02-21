#include<stdio.h>
#include<stdlib.h>

int a[50][50],n,visited[50];
int q[20],front=-1,rear=-1;
int s[20],top=-1;count=0;

void creategraph(){
    int i,j;
    printf("ENter the number of vertices in graph:");
    scanf("%d",&n);
    printf("\nenter the adjacency matrix:\n");
    for(int i=1;i<=n;i++){
        for (int j = 1; j <=n ; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
}
void bfs(int v){
    int i,cur;
    visited[v]=1;
    q[++rear]=v;
    printf("\nNODes reachable from starting vertex %d are:",v);
    while(front!=rear){
        cur=q[++front];
        for(int i=1;i<=n;i++){
            if((a[cur][i]==1)&&(visited[i]==0)){
                q[++rear]=i;
                visited[i]=1;
                printf("%d",i);
            }
        }
    }
}
void dfs(int v){
    int i;
    visited[v]=1;
    s[++top]=v;
    for(int i=1;i<=n;i++){
        if(a[v][i]==1&&visited[i]==0){
            dfs(i);
            count++;
        }
    }
}

int main(){
    int ch,start,i,j;
    creategraph();
    printf("\nMEnu\n");
    printf("\n1=>BFS\n");
    printf("\n2=>DFS \n");
    printf("\n3=>Exit\n");
    printf("\nENTer your choice:\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:for(int i=1;i<=n;i++)
                visited[i]=0;
                printf("\n enter the starting vertex:\n");
                scanf("%d",&start);
                bfs(start);
                for(int i=1;i<=n;i++){
                     if(visited[i]==0)
                     printf("\nThe vertex that is not reachable is %d",i);
                     
                }
                break;
        case 2:for(int i=1;i<=n;i++)
                visited[i]=0;
                printf("\n enter the starting vertex:\n");
                scanf("%d",&start);
                dfs(start);
                printf("Nodes reachable from starting vertex %d are:\n",start);
                for(int i=1;i<=count;i++){

                     printf("%d\t",s[i]);
                     
                }
                break;
        case 3: exit(0);
        default:printf("\nplease enter valid choice:\n");
    }

    return 0;
}