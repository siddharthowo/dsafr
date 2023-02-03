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
struct node * addtocll(struct node *p,int data){
  if(p==NULL){
    p=addtoempty(p,data);
    return p;
  }
  p=addatend(p,data);
  return p;
}
void display(struct node *last){
  struct node *p;
  p=last->next;
  do{
    printf("%d",p->info);
    p=p->next;
  }while(p!=last->next);
}
void split1(struct node *last){
  struct node *a=NULL,*b=NULL;
  struct node *p;
  int i=0;
  p=last->next;
  do{
    if(i%2==0){
      a=addtocll(a,p->info);
    }
    else{
      b=addtocll(b,p->info);
    }
    i+=1;
    p=p->next;
  }while(p!=last->next);
  printf("\nOdd position list:");
  display(a);
  printf("\nEven position list:");
  display(b);
}
/*void split2(struct node *last){
	struct node *a=last->next,*b;
	int l=0;
	do{
		l+=1;
		a=a->next;
	}while(a!=last->next);
	printf("\n%d",l);
	int i=0;
	if(l%2==0){
		a=last->next;
		do{
			b=a->next;
			a->next=b->next;
			a=a->next;
			b->next=a->next;
			b=b->next;
		}while(i<2);
	}
	printf("\nOdd position list:");
  	display(a);
  	printf("\nEven position list:");
  	display(b);
}*/
int main(){
  struct node *last=NULL;
  last=createcll(last);
  display(last);
  split1(last);
}
