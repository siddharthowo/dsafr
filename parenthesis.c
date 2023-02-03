//balancing parenthesis using stack

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
char stack_arr[MAX];
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

void push(char a)
{
	if(isFull()){
		printf("Stack overflow");
		return;
	}
	top=top+1;
	stack_arr[top]=a;
}

char pop()
{
	if (isEmpty()){
		printf("Stack underflow");
		exit(1);
	}
	return(stack_arr[top--]);
}

int match(char a , char b)
{
	if (a=='{' && b=='}')
		return 1;
	if (a=='[' && b==']')
		return 1;
	if (a=='(' && b==')')
		return 1; 
	return 0;
}


int check(char s[20])
{
	int i;
	char a;
	
	for(i=0; i<strlen(s); i++){
		if (s[i]=='{' || s[i]=='[' || s[i]=='('){
			push(s[i]);
		}
		
		if (s[i]=='}' || s[i]==']' ||s[i]==')'){
			if (isEmpty()){
				printf("Right parethesis are more than left parenthesis\n");
				return 0;
			}
			else{
				a=pop();
				if (!match(a, s[i])){
					printf("Mismatched parenthesis are %c and %c\n", a, s[i]);
					return 0;
				}
			}
		}
	}
	
	if (isEmpty()){
		printf("Balanced parenthesis\n");
		return 1;
	}
	
	else{
		printf("Left parethesis are more than Right parenthesis\n");
		return 0;
	}
}
	
int main()
{
	char s[20], a;
	int i, valid;
	printf("Enter expression: ");
	gets(s);
	valid=check(s);
	if (valid)
		printf("Valid expression");
	else
		printf("Invalid expression");
	return 0;
}
