//binary conversion using stack

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
int stack_arr[MAX];
int top=-1;

int isEmpty()
{
	if (top==-1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if (top==MAX-1)
		return 1;
	else
		return 0;
}

void push(int a)
{
	if(isFull()){
		printf("Stack overflow");
		return;
	}
	top=top+1;
	stack_arr[top]=a;
}

int pop()
{
	if (isEmpty()){
		printf("Stack underflow");
		exit(1);
	}
	return(stack_arr[top--]);
}

void binary(int n)
{
	int i, j=0, a=n;
	while (a!=0)
	{
		push(a%2);			//pushing remainders into the stack
		a=a/2;
		j++;
	}
	printf("Binary equivalent: ");
	for (i=0; i<j; i++)
		printf("%d", pop());	
}

void octal(int n){
	int i,j=0,a=n;
	while(a!=0){
		push(a%8);
		a=a/8;
		j+=1;
	}
	printf("\nOctal Equivalent:");
	for(i=0;i<j;i++){
		printf("%d",pop());
	}
}

void hex(int n){
	int i,j=0,a=n;
	int r;
	while(a!=0){
		push(a%16);
		a=a/16;
		j+=1;
	}
	printf("\nHexadecimal Equivalent:");
	for(i=0;i<j;i++){
		r=pop();
		if(r>=0 && r<=9){
			printf("%d",r);
		}
		else if(r==10){
			printf("A");
		}
		else if(r==11){
			printf("B");
		}
		else if(r==12){
			printf("C");
		}
		else if(r==13){
			printf("D");
		}
		else if(r==14){
			printf("A");
		}
		else if(r==15){
			printf("F");
		}
	}
}
int main()
{
	int n;
	printf("Enter number: ");
	scanf("%d", &n);
	binary(n);
	octal(n);
	hex(n);
	return 0;
}
