#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int front=-1;
int rear=-1;
int cq[MAX];
int isfull(){
    if((front==0 && rear==MAX-1)||(front==rear+1)){
        return 1;
    }
    return 0;
}
int isempty(){
    if(front==-1){
        return 1;
    }
    return 0;
}
void insert(int item){
    if(isfull()){
        printf("\nQueue is full");
        return;
    }
    if(front==-1){
        front+=1;
    }
    if(rear==MAX-1){
        rear=0;
    }
    else{
        rear+=1;
    }
    cq[rear]=item;
}
int del(){
    int item;
    if(isempty()){
        printf("\nEmpty Queue");
        exit(1);
    }
    item=cq[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else if(front==MAX-1){
        front=0;
    }
    else{
        front+=1;
    }
    return item;
}
int peek(){
    if(isempty()){
        printf("\nQueue is empty");
        exit(1);
    }
    return cq[front];
}
void display(){
    int i;
    if(isempty()){
        printf("\nQueue is empty");
        return;
    }
    printf("\nQueue is:");
    i=front;
    if(front<rear){
        while(i<=rear){
            printf("%d ",cq[i]);
            i+=1;
        }
    }
    else{
        while(i<MAX){
            printf("%d ",cq[i]);
            i+=1;
        }
        i=0;
        while(i<=rear){
            printf("%d ",cq[i]);
            i+=1;
        }
    }
}
int main(){
    int i,n,ele;
    printf("\nEnter number of elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter element:");
        scanf("%d",&ele);
        insert(ele);
    }
    display();
    printf("\nDequeue!");
    del();
    display();
    printf("\nElement at front of queue is:%d",peek());
}
