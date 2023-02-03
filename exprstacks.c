
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 30
char inexp1[MAX];
char postfix[MAX];
int stack1[MAX];
int top1=-1;
char infix2[MAX];
char prefix[MAX];
int stack2[MAX];
int top2=-1;
void push_postfix(int symbol)
{
	if (top1==MAX-1){
		printf("Stack overflow");
		return;
	}
	top1=top1+1;
	stack1[top1]=symbol;
}
int pop_postfix()
{
	if (top1==-1){
		printf("Stack underflow");
		exit(1);
	}
	return stack1[top1--];
}
void push_prefix(int symbol)
{
	if (top2==MAX-1){
		printf("Stack overflow");
		return;
	}
	top2=top2+1;
	stack2[top2]=symbol;
}
int pop_prefix()
{
	if (top2==-1){
		printf("Stack underflow");
		exit(1);
	}
	return stack2[top2--];
}
int priority(char symbol)
{
	switch(symbol)
	{
		case '(':
			return 0;
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
		case '^':
			return 3;
	}
}
int white_space(char symbol)
{
	if (symbol==' ' || symbol=='\t')
		return 1;
	else
		return 0;
}
void infix_to_postfix()
{
	int i,p=0;
	char next;
	char symbol;
	for (i=0; i<strlen(inexp1); i++){
		symbol=inexp1[i];
		if(!white_space(symbol)){
			switch(symbol)
			{
				case '(':
					push_postfix(symbol);
					break;
					
				case ')':
					while(next=pop_postfix() != '(')
						postfix[p++]=next;
					break;
					
				case '+':
				case '-':
				case '*':
				case '/':
				case '%':
				case '^':
					while (top1!=-1 && priority(stack1[top1])>=priority(symbol))
						postfix[p++]=pop_postfix();
					push_postfix(symbol);
					break;
					
				default:
					postfix[p++]=symbol;
			}
		}
	}
	while(top1!=-1)
		postfix[p++]=pop_postfix();
	postfix[p]='\0';
}

int eval_post()
{
	int a,b,temp,i,j,result;
	for (i=0; i<strlen(postfix); i++){
		if (postfix[i]<='9' && postfix[i]>='0')	
			push_postfix(postfix[i]-'0');
		else{
			a=pop_postfix();
			b=pop_postfix();
			switch(postfix[i]){
				case '+':
					temp=b+a;
					break;
				case '-':
					temp=b-a;
					break;
				case '*':
					temp=b*a;
					break;
				case '/':
					temp=b/a;
					break;
				case '%':
					temp=b%a;
					break;
				case '^':
					for (j=0; j<a; j++)
						b=b*b;
					temp=b;
					break;
			}
			push_postfix(temp);
		}
	}
	result=pop_postfix();
	return result;
}

void infix_to_prefix()
{
	int i,j,p=0;
	char next,symbol,temp;
	for (i=strlen(infix2)-1;i>=0;i--){
		symbol=infix2[i];
		if (!white_space(symbol)){
			switch(symbol){
				case ')':
					push_prefix(symbol);
					break;
				case '(':
					while (next=pop_prefix() != ')')
						prefix[p++]=next;
					break;
				case '+':
				case '-':
				case '*':
				case '/':
				case '%':
				case '^':
					while (top2!=-1 && priority(stack2[top2])>priority(symbol))
						prefix[p++]=pop_prefix();
					push_prefix(symbol);
					break;
				default:
					prefix[p++]=symbol;
			}
		}
	}
	while (top2!=-1)
		prefix[p++]=pop_prefix();
	prefix[p]='\0';
	for (i=0,j=p-1; i<j; i++,j--){
		temp=prefix[i];
		prefix[i]=prefix[j];
		prefix[j]=temp;
	}
}
int eval_pre()
{
	int a, b, temp, result, i;
	for (i=strlen(prefix)-1;i>=0; i--){
		if (prefix[i]<='9' && prefix[i]>='0')
			push_prefix(prefix[i]-48);
		else{
			a=pop_prefix();
			b=pop_prefix();
			switch(prefix[i]){
				case '+':
					temp=a+b;
					break;
					
				case '-':
					temp=a-b;
					break;
					
				case '*':
					temp=a*b;
					break;
					
				case '/':
					temp=a/b;
					break;
					
				case '%':
					temp=a%b;
					break;
					
				case '^':
					temp=pow(a,b);
					break;
			}
			push_prefix(temp);
		}
	}
	result=pop_prefix();
	return result;
}

int main()
{
	int ch,res;
	while (1)
	{
		printf("\n1.Convert an Infix expression to Postfix");
		printf("\n2.Convert an Infix expression to Prefix");
		printf("\n3.Evaluate a Postfix expression");
		printf("\n4.Evaluate a Prefix expression");
		printf("\n5.Exit"); 
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter infix expression: ");
				scanf("%s",inexp1);
				infix_to_postfix();
				printf("Postfix expression:%s\n",postfix);
				break;
			case 2:
				printf("Enter infix expression:");
				scanf("%s",infix2);
				infix_to_prefix();
				printf("Prefix expression: %s\n",prefix);
				break;
			case 3:
				printf("\nEnter postfix expression:");
				scanf("%s",postfix);
				res=eval_post();
				printf("\nValue of expression:%d",res);
				break;
			case 4:
				printf("\nEnter prefix expression:");
				scanf("%s",prefix);
				res=eval_pre();
				printf("\nValue of expression:%d",res);
				break;
			case 5:
				exit(1);
			default:
				printf("\nEnter a valid choice");
		}
	}
	return 0;
}
