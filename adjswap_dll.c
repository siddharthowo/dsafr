#include<stdio.h>
#include<stdlib.h>
struct node{
  struct node *prev;
  int info;
  struct node *next;
};
struct node * addtoempty(struct node *start,int data){
  struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  temp->prev=NULL;
  temp->info=data;
  temp->next=NULL;
  start=temp;
  return start;
}
struct node * addatend(struct node *start,int data){
  struct node *temp,*p;
  temp=(struct node *)malloc(sizeof(struct node));
  p=start;
  while(p->next!=NULL){
    p=p->next;
  }
  temp->prev=p;
  p->next=temp;
  temp->info=data;
  temp->next=NULL;
  return start;
}
struct node * createdll(struct node *start){
  int i,n,d;
  printf("\nEnter number of items:");
  scanf("%d",&n);
  start=NULL;
  if(n==0){
    return start;
  }
  printf("\nEnter element:");
  scanf("%d",&d);
  start=addtoempty(start,d);
  for(i=1;i<n;i++){
    printf("\nEnter element:");
    scanf("%d",&d);
    start=addatend(start,d);
  }
  return start;
}
void display(struct node *start){
  struct node *p;
  for(p=start;p!=NULL;p=p->next){
    printf("%d",p->info);
  }
}
struct node * swap(struct node *start){
	struct node *p=start,*t1,*t2;
	struct node *q=p->next;
	int n=0;
	while(p!=NULL){
		n+=1;
		p=p->next;
	}
	if(n<=1){
		return start;
	}
	p=start;
	p->next=q->next;
	p->prev=q;
	q->prev=NULL;
	q->next->prev=p;
	q->next=p;
	t2=q;
	start=q;
	t1=p->next;
	if(n%2!=0){
		while(t1->next!=NULL){
			t2=t1->next;
			t1->prev->next=t2;
			t1->next=t2->next;
			t2->prev=t1->prev;
			t2->next->prev=t1;
			t2->next=t1;
			t1->prev=t2;
			t1=t1->next;
		}
	}
	else{
		while(t1!=NULL){
			t2=t1->next;
			t1->prev->next=t2;
			t1->next=t2->next;
			t2->prev=t1->prev;
			if(t2->next!=NULL){
				t2->next->prev=t1;
			}
			t2->next=t1;
			t1->prev=t2;
			t1=t1->next;
		}	
	}
	return start;
}
int main(){
  struct node *start=NULL;
  start=createdll(start);
  printf("\nEntered list is:");
  display(start);
  start=swap(start);
  printf("\nThe list after swapping of adjacent elements:");
  display(start);
}
