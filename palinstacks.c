//checking for palindrome using stack

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

int palindrome(char s[10])
{
	int i, mid=strlen(s)/2;
	char a;
	
	for (i=0; i<mid; i++)				//pushin elements till middle of the string in the array
		push(s[i]);
	if (strlen(s)%2 != 0)				//if length of string is odd, ignore the middle character
		i++;
	for (i=mid+1; i<strlen(s); i++)		//popping characters from stack and comparing them with remainign elements of string
	{
		a=pop();
		if (a != s[i])
			return 0;
	}
	return 1;
}

int main()
{
	char s[10];
	printf("Enter string: ");
	gets(s);
	if (palindrome(s))
		printf("Palindrome");
	else
		printf("Not a palindrome");
	return 0;
}
