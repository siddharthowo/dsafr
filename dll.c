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
  printf("\n");
}
struct node * addatbeg(struct node *start,int data){
  struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  temp->info=data;
  temp->prev=NULL;
  temp->next=start;
  start->prev=temp;
  start=temp;
  return start;
}
struct node * addbefore(struct node *start,int item,int data){
  struct node *temp,*p;
  if(start->info==item){
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->prev=NULL;
    temp->next=start;
    start->prev=temp;
    start=temp;
    return start;
  }
  else{
  p=start;
  while(p!=NULL){
      if(p->info==item){
        temp=(struct node *)malloc(sizeof(struct node));
        temp->info=data;
        temp->prev=p->prev;
        temp->next=p;
        p->prev->next=temp;
        p->prev=temp;
        return start;
      }
      p=p->next;
  }
  printf("\nElement not found");
  return start;
  }
}
struct node * addafter(struct node *start,int item,int data){
  struct node *temp,*p;
  p=start;
  while(p!=NULL){
    if(p->info==item){
      temp=(struct node *)malloc(sizeof(struct node));
      temp->info=data;
      temp->prev=p;
      temp->next=p->next;
      if(p->next!=NULL){
        p->next->prev=temp;
      }
      p->next=temp;
      return start;
    }
    p=p->next;
  }
  printf("\nItem not found");
  return start;
}
struct node * del(struct node *start,int item){
  struct node *p,*temp;
  if(start==NULL){
    printf("\nList is empty");
    return start;
  }
  if(start->info==item){
    temp=start;
    start=start->next;
    start->prev=NULL;
    free(temp);
  }
  else{
    p=start;
    while(p->next!=NULL){
      if(p->next->info==item){
        temp=p->next;
        p->next=temp->next;
        if(temp->next!=NULL){
          temp->next->prev=p;
        }
        free(temp);
      }
      else{
        p=p->next;
      }
    }
  }
  return start;
}
struct node * rev(struct node *start){
  struct node *p1,*p2;
  p1=start;
  p2=p1->next;
  p1->prev=p2;
  p1->next=NULL;
  while(p2!=NULL){
    p2->prev=p2->next;
    p2->next=p1;
    p1=p2;
    p2=p2->prev;
  }
  start=p1;
  return start;
}
void search(struct node *start,int item){
  struct node *p=start;
  while(p!=NULL){
    if(p->info==item){
      printf("\nItem found in list");
      return;
    }
    p=p->next;
  }
  printf("\nItem not present in list");
  return;
}
int count(struct node *start){
  int i=0;
  struct node *p=start;
  while(p!=NULL){
    i+=1;
    p=p->next;
  }
  return i;
}
void pos(struct node *start,int item){
  struct node *p=start;
  int pos=0;
  while(p!=NULL){
    if(p->info==item){
      printf("\nPosition of element:%d",pos+1);
      return;
    }
    else{
      pos+=1;
      p=p->next;
    }
  }
  printf("\nItem not found");
  return;
}
int main(){
  struct node *start=NULL;
  start=createdll(start);
  display(start);
  printf("\nEnter element after:");
  int item,ele;
  scanf("%d",&item);
  printf("\nEnter element:");
  scanf("%d",&ele);
  start=addafter(start,item,ele);
  display(start);
  printf("\nEnter element before:");
  int item1,ele1;
  scanf("%d",&item1);
  printf("\nEnter element:");
  scanf("%d",&ele1);
  start=addbefore(start,item1,ele1);
  display(start);
  int dn;
  printf("\nEnter element to be deleted:");
  scanf("%d",&dn);
  start=del(start,dn);
  display(start);
  start=addatbeg(start,5);
  printf("\nAdding 5 at beginning of list");
  display(start);
  start=rev(start);
  printf("\nReversed list:");
  display(start);
  printf("\nLength of list is:%d",count(start));
  search(start,5);
  pos(start,3);
}
