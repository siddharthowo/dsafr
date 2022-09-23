#include<stdio.h>
struct node{
	int info;
	struct node *link;
};
int main(){
	struct node * addatabeg(struct node *start,int data){
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		temp->link=start;
		start=temp;
		return start;
	}
	struct node * addataend(struct node *start,int data){
		struct node *p;
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		temp->info=data;
		p=start;
		while(p->link!=NULL){
			p=p->link;
		}
		p->link=temp;
		temp->link=NULL;
		return start;
	}
	struct node * createlist(struct node *start){
		int i,n,data;
		printf("Enter number of elements:");
		scanf("%d",&n);
		start=NULL;
		if(n==0){
			return start;
		}
		printf("Enter element:");
		scanf("%d",&data);
		start=addatabeg(start,data);
		for(i=1;i<n;i++){
			printf("Enter element:");
			scanf("%d",&data);
			start=addataend(start,data);
		}
		return start;
	}
	void display(struct node *start){
		struct node *p;
		if(start==NULL){
			printf("The list is empty");
			return;
		}
		p=start;
		while(p!=NULL){
			printf("%d",p->info);
			p=p->link;
		}
	}
	struct node *start=NULL;
	start=createlist(start);
	display(start);
}
