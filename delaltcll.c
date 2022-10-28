#include<stdio.h>
#include<stdlib.h>
struct node{
  int info;
  struct node *next;
};
struct node * addtoempty(struct node *last,int data){
  struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  temp->info=data;
  last=temp;
  last->next=last;
  return last;
}
struct node * addatend(struct node *last,int data){
  struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  temp->info=data;
  temp->next=last->next;
  last->next=temp;
  last=temp;
  return last;
}
struct node * createcll(struct node *last){
  int i,n,d;
  printf("\nEnter number of items:");
  scanf("%d",&n);
  last=NULL;
  if(n==0){
    return last;
  }
  printf("\nEnter element:");
  scanf("%d",&d);
  last=addtoempty(last,d);
  for(i=1;i<n;i++){
    printf("\nEnter element:");
    scanf("%d",&d);
    last=addatend(last,d);
  }
  return last;
}
struct node * delalt(struct node *last){
	if(last==NULL){
		printf("\nList is empty");
		return last;
	}
	int l=0;
	struct node *p=last->next,*temp;
	do{
		l+=1;
		p=p->next;
	}while(p!=last->next);
	p=last->next;
	if(l%2==0){
		while(p->next!=last){
			temp=p->next;
			p->next=temp->next;
			free(temp);
			p=p->next;
		}
	}
	else{
		while(p!=last){
			temp=p->next;
			p->next=temp->next;
			free(temp);
			p=p->next;
		}
	}
	if(l%2==0){
		temp=last;
		p->next=last->next;
		last=p;
		free(temp);
	}
	return last;
}
void display(struct node *last){
  struct node *p;
  if(last==NULL){
  	printf("\nList is empty");
  }
  p=last->next;
  do{
    printf("%d",p->info);
    p=p->next;
  }while(p!=last->next);
}
int main(){
  struct node *last=NULL;
  last=createcll(last);
  printf("List is:");
  display(last);
  last=delalt(last);
  printf("\n");
  printf("List after deletion of alternate nodes:");
  display(last);
}
