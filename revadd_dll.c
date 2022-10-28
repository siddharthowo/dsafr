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
  printf("\nEnter number of digits:");
  scanf("%d",&n);
  start=NULL;
  if(n==0){
    return start;
  }
  printf("\nEnter digit:");
  scanf("%d",&d);
  start=addtoempty(start,d);
  for(i=1;i<n;i++){
    printf("\nEnter digit:");
    scanf("%d",&d);
    start=addatend(start,d);
  }
  return start;
}
void display(struct node *start){
  struct node *p;
  printf("\nNumber is:");
  for(p=start;p!=NULL;p=p->next){
    printf("%d",p->info);
  }
}
struct node * add(struct node *start,struct node *start1,struct node *start2){
	struct node *p1=start;
	struct node *p2=start1;
	int carry;
	int data=p1->info+p2->info;
	if(data>9){
		carry=1;
	}
	int sum=data%10;
	start2=addtoempty(start2,sum);
	p1=p1->next;
	p2=p2->next;
	while(p1!=NULL&&p2!=NULL){
		data=p1->info+p2->info;
		if(carry==1){
			data+=1;
		}
		if(data>9){
			carry=1;
		}
		else{
			carry=0;
		}
		sum=data%10;
		start2=addatend(start2,sum);
		p1=p1->next;
		p2=p2->next;
	}
	if(p1!=NULL){
		sum=p1->info+carry;
		if(sum>9){
			carry=1;
		}
		else{
			carry=0;
		}
		start2=addatend(start2,sum);
		p1=p1->next;
	}
	if(p2!=NULL){
		sum=p2->info+carry;
		if(sum>9){
			carry=1;
		}
		else{
			carry=0;
		}
		start2=addatend(start2,sum);
		p2=p2->next;
	}
	if(carry==1){
		start2=addatend(start2,1);
	}
	return start2;
}
struct node * rev(struct node *start){
	struct node *p1,*p2;
	p1=start;
	p2=p1->next;
	p1->next=NULL;
	p1->prev=p2;
	while(p2!=NULL){
		p2->prev=p2->next;
		p2->next=p1;
		p1=p2;
		p2=p2->prev;
	}
	start=p1;
	return start;
}
int main(){
  struct node *start=NULL,*start1=NULL,*start2=NULL;
  printf("\nEnter 1st Number:");
  start=createdll(start);
  printf("\nEnter 2nd Number:");
  start1=createdll(start1);
  start=rev(start);
  start1=rev(start1);
  printf("\n");
  display(start);
  display(start1);
  start2=add(start,start1,start2);
  display(start2);
}
