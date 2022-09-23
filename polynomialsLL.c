#include<stdio.h>
#include<stdlib.h>
struct poly{
	int coeff;
	int exp;
	struct poly *link;
};
struct poly * addatbeg(struct poly *start,int cf,int ex){
	struct poly *temp;
	temp=(struct poly *)malloc(sizeof(struct poly));
	temp->coeff=cf;
	temp->exp=ex;
	temp->link=start;
	start=temp;
	return start;
}
struct poly * addbefore(struct poly *start,int item,int data1,int data2){
	struct poly *temp,*p;
	if(start->exp==item){
		temp=(struct poly *)malloc(sizeof(struct poly));
		temp->coeff=data1;
		temp->exp=data2;
		temp->link=start;
		start=temp;
		return start;
	}
	p=start;
	while(p->link!=NULL){
		if(p->link->exp==item){
			temp=(struct poly *)malloc(sizeof(struct poly));
			temp->coeff=data1;
			temp->exp=data2;
			temp->link=p->link;
			p->link=temp;
			return start;
		}
		p=p->link;
	}
	return start;
}
struct poly * addatend(struct poly *start,int cf,int ex){
	struct poly *temp,*p;
	p=start;
	temp=(struct poly *)malloc(sizeof(struct poly));
	temp->coeff=cf;
	temp->exp=ex;
	while(p->link!=NULL){
		p=p->link;
	}
	temp->link=NULL;
	p->link=temp;
	return start;
}
struct poly * del(struct poly *start,int data){
	struct poly *tmp,*p;
	if(start->coeff=data) {
	tmp=start;
	start=start->link;
	free(tmp);
	return start;
	}
	p=start;
	while(p->link!=NULL) {
	if(p->link->coeff==data){
	tmp=p->link;
	p->link=tmp->link;
	free(tmp);
	return start;
	}
	p=p->link;
	}
	printf("\nElement %d not found\n",data);
	return start;
}
struct poly * crp(struct poly *start){
	struct poly *temp,*p;
	int n;
	printf("\nEnter number of terms:");
	scanf("%d",&n);
	start=NULL;
	if(n==0){
		return start;
	}
	p=start;
	int cf,ex;
	printf("Enter coefficient:");
	scanf("%d",&cf);
	printf("Enter exponent:");
	scanf("%d",&ex);
	start=addatbeg(p,cf,ex);
	int i=0;
	while(i<n-1){
		int cf1,ex1,tpe;
		printf("Enter coeff:");
		scanf("%d",&cf1);
		printf("Enter exp:");
		scanf("%d",&ex1);
		struct poly *k;
		for(k=start;k!=NULL;k=k->link){
			if(ex1>k->exp){
				start=addbefore(start,k->exp,cf1,ex1);
				break;
			}
			else{
				start=addatend(start,cf1,ex1);
				break;
			}
		}
		i+=1;
	}
	return start;
}
void display(struct poly *start){
	struct poly *p;
	p=start;
	while(p!=NULL){
		printf("%d",p->coeff);
		printf("x^%d\t",p->exp);
		p=p->link;
	}
}
void main(){
struct poly *start1=NULL;
start1=crp(start1);
display(start1);
struct poly *start2=NULL;
start2=crp(start2);
display(start2);
while(1){
	printf("\n\tPolynomial Calculator\n1.Add the two polynomials\n2.Multiply the two polynomials\n3.Modify polynomials\n4.Exit");
	printf("\nEnter your choice:");
	int ch;
	scanf("%d",&ch);
	switch (ch){
		case 1:{
		struct poly *temp1,*temp2;
		temp1=start1;
		temp2=start2;
		while(temp1!=NULL||temp2!=NULL){
			if(temp1->exp==temp2->exp){
				printf("+%dx^%d",temp1->coeff+temp2->coeff,temp1->exp);
				temp1=temp1->link;
				temp2=temp2->link;
			}
			else if(temp1->exp>temp2->exp){
				printf("+%dx^%d",temp1->coeff,temp1->exp);
				temp1=temp1->link;
			}
			else if(temp2->exp>temp1->exp){
				printf("+%dx^%d",temp2->coeff,temp2->exp);
				temp2=temp2->link;
			}
			if(temp1==NULL||temp2==NULL){
				if(temp1!=NULL){
					printf("+%dx^%d",temp1->coeff,temp1->exp);
					temp1=temp1->link;
				}
				else{
					if(temp2!=NULL){
					printf("+%dx^%d",temp2->coeff,temp2->exp);
					temp2=temp2->link;
					}
				}
			}
		}
		break;
		}
		case 2:{
			struct poly *temp1,*temp2;
			temp1=start1;
			printf("Product:");
			while(temp1!=NULL){
				temp2=start2;
				while(temp2!=NULL){
					printf("%dx^%d+",temp1->coeff*temp2->coeff,temp1->exp+temp2->exp);
					temp2=temp2->link;
				}
				temp1=temp1->link;
			}
			break;
		}
		case 3:{
			printf("1.Insert a term\n2.Delete a term\nEnter your choice:");
			int ch1;
			scanf("%d",&ch1);
			switch(ch1){
				case 1:{
				printf("\nAdd term before term with coefficient?:");
				int no,cfa,exa;
				scanf("%d",&no);
				printf("\nCoefficient:");
				scanf("%d",&cfa);
				printf("\nExponent:");
				scanf("%d",&exa);
				printf("\n1.Add to first polynomial\n2.Add to second polynomial");
				printf("\nEnter your choice:");
				int a1;
				scanf("%d",&a1);
				if(a1==1){
				start1=addbefore(start1,no,cfa,exa);
				printf("\nTerm added successfully!");
				}
				else if(a1==2){
				start2=addbefore(start2,no,cfa,exa);
				printf("\nTerm added successfully!");
				}
				else{
					printf("\nPlease enter a valid choice");
					break;
				}
				break;
			}
			case 2:{
				printf("\nDelete from\n1.First polynomial\n2.Second Polynomial");
				int o1,cd;
				printf("Enter your choice:");
				scanf("%d",&o1);
				if(o1==1){
					printf("\nEnter coefficient of term to be deleted");
					scanf("%d",&cd);
					start1=del(start1,cd);
				}
				else if(o1==2){
					printf("\nEnter coefficient of term to be deleted");
					scanf("%d",&cd);
					start2=del(start2,cd);
				}
				else{
					printf("\nPlease enter a valid choice");
					break;
				}
			}
			}
			break;
		}
		case 4:{
			exit(0);
		}
		default:{
			printf("\nEnter a valid choice");
			break;
		}
	}
}
}

	
	
	
	
