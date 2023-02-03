#include<stdio.h>
#define MAX 50
int graph[MAX][MAX];
int n;
void create(){
    int vs,vd;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    int me=n*(n-1);
    for(int i=1;i<=me;i++){
        printf("\nEnter edge(-1 -1 to exit):");
        scanf("%d %d",&vs,&vd);
        if(vs==-1 && vd==-1){
            break;
        }
        else if(vs<0 || vd<0 || vs>=n || vd>=n){
            printf("\nInvalid Vertex");
            i--;
        }
        else{
            graph[vs][vd]=1;
        }
    }
}
void display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
void deledge(int vs,int vd){
    if(vs<0 || vd<0 || vs>=n || vd>=n || graph[vs][vd]==0){
        printf("\nEdge does not exist");
    }
    else{
        graph[vs][vd]=0;
    }
}
void insertedge(int vs,int vd){
    if(vs<0 || vs>=n){
        printf("\nSource vertex doesnt exist");
        return;
    }
    else if(vd<0 || vd>=n){
        printf("\nDestination vertex doesnt exist");
        return;
    }
    graph[vs][vd]=1;
}
int main(){
    create();
    printf("\nDirected graph is:\n");
    display();
    insertedge(5,2);
    printf("\nGraph after insertion of edge from 5 to 2\n");
    display();
    deledge(5,2);
    printf("\nGraph after deletion of edge from 5 to 2\n");
    display();
}
