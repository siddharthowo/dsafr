#include<stdio.h>
#include<stdlib.h>
struct set{
	int info;
	struct set *link;
};
//add node at beginning of list
struct set * addatabeg(struct set *start,int data){
	struct set *temp1;
	temp1=(struct set *)malloc(sizeof(struct set));
	temp1->link=start;
	temp1->info=data;
	start=temp1;
	return start;
}
//add data at end of the linked list
struct set * addataend(struct set *start,int data){
	struct set *p;
	struct set *temp;
	temp=(struct set *)malloc(sizeof(struct set));
	temp->info=data;
	p=start;
	while(p->link!=NULL){
		p=p->link;
	}
	p->link=temp;
	temp->link=NULL;
	return start;
}
//creating a linked list
struct set * createset(struct set *start){
	int i,n,data;
	printf("Enter number of elements:");
	scanf("%d",&n);
	start=NULL;
	if(n==0){
		return start;
	}
	printf("Enter data to be entered:");
	scanf("%d",&data);
	start=addatabeg(start,data);
	for(i=2;i<=n;i++){
		printf("Enter data to be entered:");
		scanf("%d",&data);
		start=addataend(start,data);
	}
	return start;
}
//displaying a linked list
void display(struct set *start){
	struct set *p;
	if(start==NULL){
		printf("Set is empty :(");
		return;
	}
	p=start;
	while(p!=NULL){
		printf("%d",p->info);
		p=p->link;
	}
}
int main(){
	struct set *start1=NULL;
	struct set *start2=NULL;
	start1=createset(start1);
	start2=createset(start2);
	printf("\nSet 1:");
	display(start1);
	printf("\nSet 2:");
	display(start2);
	while(1){
	printf("\n\thelo\n1.Intersection\n2.Union\n3.Difference\n4.Exit\nEnter your choice:");
	int ch;
	scanf("%d",&ch);
	switch(ch){
		case 1:{
			struct set *temp1,*temp2;
			temp1=start1;
			printf("Intersection:");
			while(temp1!=NULL){
				temp2=start2;
				while(temp2!=NULL){
					if(temp1->info==temp2->info){
						printf("%d",temp1->info);
					}
					temp2=temp2->link;
				}
				temp1=temp1->link;
			}
			break;
		}
		case 2:{
			display(start1);
			display(start2);
			break;
		}
		case 3:{
			struct set *t1=start1,*t2;
			while(t1!=NULL){
				t2=start2;
				while(t2->link!=NULL){
				if(t1->info!=t2->info){
					printf("%d",t1->info);
					break;
				}
				t2=t2->link;
				}
				t1=t1->link;
			}
			break;
		}
		case 4:{
			exit(0);
		}
	}
}
}
