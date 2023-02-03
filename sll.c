#include<stdio.h>
struct node{
	int info;
	struct node *link;
};
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
		printf("%d ",p->info);
		p=p->link;
	}
}
struct node * addafter(struct node *start,int item,int data){
	struct node *p,*temp;
	if(start==NULL){
		return NULL;
	}
	p=start;
	while(p!=NULL){
		if(p->info==item){
			temp=(struct node *)malloc(sizeof(struct node));
			temp->link=p->link;
			temp->info=data;
			p->link=temp;
			return start;
		}
		p=p->link;
	}
	printf("\nItem not found");
	return start;
	}
struct node * addbefore(struct node *start,int item,int data){
	struct node *temp,*p;
	if(start==NULL){
		return NULL;
	}
	p=start;
	if(start->info==item){
		temp=(struct node *)malloc(sizeof(struct node));
		temp->link=start;
		temp->info=data;
		start=temp;
		return start;
	}
	while(p->link!=NULL){
		if(p->link->info==item){
			temp=(struct node *)malloc(sizeof(struct node));
			temp->link=p->link;
			temp->info=data;
			p->link=temp;
			return start;
		}
		p=p->link;
	}
	printf("\nItem not found");
	return start;
}
struct node * del(struct node *start,int item){
	struct node *p,*temp;
	if(start==NULL){
		printf("\nEmpty List");
		return NULL;
	}
	if(start->info==item){
		temp=start;
		start=temp->link;
		free(temp);
		return start;
	}
	p=start;
	while(p->link!=NULL){
		if(p->link->info==item){
			temp=p->link;
			p->link=temp->link;
			free(temp);
			return start;
		}
		p=p->link;
	}
	printf("\nItem not found");
	return start;
}
void search(struct node *start,int item){
	struct node *p;
	if(start==NULL){
		printf("\nList is empty");
		return;
	}
	p=start;
	while(p!=NULL){
		if(p->info==item){
			printf("\nItem found in list");
			return;
		}
		p=p->link;
	}
	printf("\nItem not found in list");
	return;
}
int count(struct node *start){
	struct node *p=start;
	int c=0;
	while(p!=NULL){
		c+=1;
		p=p->link;
	}
	return c;
}
void pos(struct node *start,int item){
	struct node *p;
	int pos=0;
	p=start;
	while(p!=NULL){
		if(p->info==item){
			printf("\nItem found in list!Position:%d",pos+1);
			return;
		}
		p=p->link;
		pos+=1;
	}
	printf("\nItem not found in list");
	return;
}
struct node * rev(struct node * start){
    struct node * p=NULL;
    struct node * c=start;
    struct node * n=NULL;
    while(c!=NULL){
        n=c->link;
        c->link=p;
        p=c;
        c=n;
    }
	start=p;
	return start;
}
int main(){
	struct node *start=NULL;
	start=createlist(start);
	display(start);
	start=addafter(start,5,6);
	printf("\nAdding 6 after 5:");
	display(start);
	printf("\n");
	start=addbefore(start,3,9);
	printf("\nAdding 9 before 3:");
	display(start);
	printf("\nDeleting node 4");
	start=del(start,4);
	printf("\n");
	display(start);
	start=rev(start);
	printf("\nReversed List:");
	display(start);
	printf("\nPosition of 2 in list:");
	pos(start,2);
	printf("\nSearch for 6:");
	search(start,6);
}
