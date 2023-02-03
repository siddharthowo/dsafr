#include<stdio.h>
#include<stdlib.h>
#define max 6
int front=-1;
int rear=-1;
int que[max];
int isfull(){
  if(rear==max-1){
    return 1;
  }
  return 0;
}
int isempty(){
  if(front==-1){
    return 1;
  }
  if(front=rear+1){
    return 1;
  }
  return 0;
}
void insert(int item){
  if(isfull()){
    printf("\nQueue Overflow");
    return;
  }
  if(front==-1){
    front=0;
  }
  rear+=1;
  que[rear]=item;
  return;
}
void del(){
  if(front==-1||front==rear+1){
    printf("\nQueue Underflow");
    return;
  }
  front+=1;
  return;
}
void display(){
  int i;
  if(front==-1||front==rear+1){
    printf("\nQueue is empty");
    return;
  }
  for(i=front;i<=rear;i++){
    printf("%d",que[i]);
  }
}
int peek(){
	return que[front];
}
int main(){
	printf("\nNo of elements:");
	int i,n,e;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter element:");
		scanf("%d",&e);
		insert(e);
	}
	display();
	printf("\nItem at front of queue:%d",peek());
	del();
	printf("\nQueue after dequeueing:");
	display();
}
