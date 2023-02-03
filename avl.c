#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
struct node{
	int info;
	struct node *lchild;
	struct node *rchild;
	int balance;
};
void inorder(struct node *root){
	if (root==NULL)
		return;
	inorder(root->lchild);
	printf("%d ", root->info);
	inorder(root->rchild);
}
struct node * RotateLeft(struct node *pptr){
	struct node *aptr;
	aptr=pptr->rchild;
	pptr->rchild=aptr->lchild;
	aptr->lchild=pptr;
	return aptr;
}

struct node * RotateRight(struct node *pptr)
{
	struct node *aptr;
	aptr=pptr->lchild;
	pptr->lchild=aptr->rchild;
	aptr->rchild=pptr;
	return aptr;
}

struct node * insert_LeftBalance(struct node *pptr)
{
	struct node *aptr, *bptr;
	aptr=pptr->lchild;
	if (aptr->balance==1){
		pptr->balance=0;
		aptr->balance=0;
		pptr=RotateRight(pptr);
	}
	else{
		bptr=aptr->rchild;
		switch(bptr->balance){
			case -1:
				pptr->balance=0;
				aptr->balance=1;
				break;
				
			case 1:
				pptr->balance=-1;
				aptr->balance=0;
				break;
				
			case 0:
				pptr->balance=0;
				aptr->balance=0;
		}
		bptr->balance=0;
		pptr->lchild=RotateLeft(aptr);
		pptr=RotateRight(pptr);
	}
	return pptr;
}

struct node * insert_left_check(struct node *pptr, int *taller)
{
	switch(pptr->balance){
		case 0:
			pptr->balance=1;
			break;
		
		case 1:
			pptr->balance=0;
			*taller=FALSE;
			break;
	}
	return pptr;
}

struct node * insert_RightBalance(struct node *pptr)
{
	struct node *aptr, *bptr;
	aptr=pptr->rchild;
	if(aptr->balance==-1){
		pptr->balance=0;
		aptr->balance=0;
		pptr=RotateLeft(pptr);
	}
	else{
		bptr=aptr->lchild;
		switch(bptr->balance){
			case -1:
				pptr->balance=1;
				aptr->balance=0;
				break;
				
			case 1:
				pptr->balance=0;
				aptr->balance=-1;
				break;
				
			case 0:
				pptr->balance=0;
				aptr->balance=0;
		}
		bptr->balance=0;
		pptr->rchild=RotateRight(aptr);
		pptr=RotateLeft(pptr);
	}
	return pptr;
}
struct node * insert_right_check(struct node *pptr, int *ptaller)
{
	switch(pptr->balance){
		case 0:
			pptr->balance=-1;
			break;
		case 1:
			pptr->balance=0;
			*ptaller=FALSE;
			break;
		case -1:
			pptr=insert_RightBalance(pptr);
			*ptaller=FALSE;
	}
	return pptr;
}

struct node * insert(struct node *pptr, int ikey)
{
	static int taller;
	if (pptr==NULL){
		pptr=(struct node*)malloc(sizeof(struct node));
		pptr->info=ikey;
		pptr->lchild=NULL;
		pptr->rchild=NULL;
		pptr->balance=0;
		taller=TRUE;
	}
	else if(ikey<pptr->info){
		pptr->lchild=insert(pptr->lchild, ikey);
		if (taller==TRUE)
			pptr=insert_left_check(pptr, &taller);
	}
	else if(ikey>pptr->info){
		pptr->rchild=insert(pptr->rchild, ikey);
		if (taller==TRUE)
			pptr=insert_right_check(pptr, &taller);
	}
	else{
		printf("Duplicate key\n");
		taller=FALSE;
	}
	return pptr;
}

struct node * del_RightBalance(struct node *pptr, int *pshorter)
{
	struct node *aptr, *bptr;
	aptr=pptr->rchild;
	if (aptr->balance==0){
		pptr->balance=-1;
		aptr->balance=1;
		*pshorter=FALSE;
		pptr=RotateLeft(pptr);
	}
	else if (aptr->balance==-1){
		pptr->balance=0;
		aptr->balance=0;
		pptr=RotateLeft(pptr);
	}
	else{
		bptr=aptr->lchild;
		switch(bptr->balance){
			case 0:
				pptr->balance=0;
				aptr->balance=0;
				break;
			case 1:
				pptr->balance=0;
				aptr->balance=-1;
				break;
			case -1:
				pptr->balance=1;
				aptr->balance=0;
		}
		bptr->balance=0;
		pptr->rchild=RotateRight(aptr);
		pptr=RotateLeft(pptr);
	}
	return pptr;
}

struct node * del_left_check(struct node *pptr, int *pshorter)
{
	switch(pptr->balance){
		case 0:
			pptr->balance=-1;
			*pshorter=FALSE;
			break;
		case 1:
			pptr->balance=0;
			break;
		case -1:
			pptr=del_RightBalance(pptr, pshorter);
	}
	return pptr;
}

struct node * del_LeftBalance(struct node *pptr, int *pshorter)
{
	struct node *aptr, *bptr;
	aptr=pptr->lchild;
	if (aptr->balance==0){
		pptr->balance=1;
		aptr->balance=-1;
		*pshorter=FALSE;
		pptr=RotateRight(pptr);
	}
	else if (aptr->balance==1){
		pptr->balance=0;
		aptr->balance=0;
		pptr=RotateRight(pptr);
	}
	else{
		bptr=aptr->rchild;
		switch(bptr->balance){
			case 0:
				pptr->balance=0;
				aptr->balance=0;
				break;
			case 1:
				pptr->balance=-1;
				aptr->balance=0;
				break;
			case -1:
				pptr->balance=0;
				aptr->balance=1;
		}
		bptr->balance=0;
		pptr->lchild=RotateLeft(aptr);
		pptr=RotateRight(pptr);
	}
	return pptr;
}

struct node * del_right_check(struct node *pptr, int *pshorter)
{
	switch(pptr->balance){
		case 0:
			pptr->balance=1;
			*pshorter=FALSE;
			break;
		case -1:
			pptr->balance=0;
			break;
		case 1:
			pptr=del_LeftBalance(pptr, pshorter);
	}
	return pptr;	
}

struct node * del(struct node *pptr, int dkey)
{
	struct node *temp, *succ;
	static int shorter;
	if (pptr==NULL){
		printf("Key not present\n");
		shorter=FALSE;
		return pptr;
	}
	if (dkey < pptr->info){
		pptr->lchild=del(pptr->lchild, dkey);
		if (shorter==TRUE)
			pptr=del_left_check(pptr, &shorter);
	}
	else if (dkey > pptr->info){
		pptr->rchild=del(pptr->rchild, dkey);
		if (shorter==TRUE)
			pptr=del_right_check(pptr, &shorter);
	}
	else{
		if (pptr->lchild!=NULL && pptr->rchild!=NULL){
			succ=pptr->rchild;
			while(succ->lchild)
				succ=succ->lchild;
			pptr->info=succ->info;
			pptr->rchild=del(pptr->rchild, succ->info);
			if (shorter==TRUE)
				pptr=del_right_check(pptr, &shorter);	
		}
		else{
			temp=pptr;
			if (pptr->lchild!=NULL)
				pptr=pptr->lchild;
			else if (pptr->rchild!=NULL)
				pptr=pptr->rchild;
			else
				pptr=NULL;
			free(temp);
			shorter=TRUE;
		}
	}
	return pptr;
}

struct node * search(struct node *ptr, int skey)
{
	if (ptr==NULL){
		printf("Key not present\n");
		return NULL;
	}
	else if (skey < ptr->info)
		return search(ptr->lchild, skey);
	else if (skey > ptr->info)
		return search(ptr->rchild, skey);
	else
		return ptr;
}
struct node * max(struct node *ptr)
{
	if (ptr==NULL)
		return NULL;
	else if (ptr->rchild==NULL)
		return ptr;
	else
		return max(ptr->rchild);
}

struct node * min(struct node *ptr)
{
	if (ptr==NULL)
		return NULL;
	else if (ptr->lchild==NULL)
		return ptr;
	else
		return min(ptr->lchild);
}

void descending(struct node *ptr)
{
	if (ptr==NULL)
		return;
	descending(ptr->rchild);
	printf("%d ", ptr->info);
	descending(ptr->lchild);
}
int getWidth(struct node *root, int level)
{
	if (root==NULL)
		return 0;
	if (level==1)
		return 1;
	else if (level>1)
		return getWidth(root->lchild, level-1)+getWidth(root->rchild, level-1);
}

int height(struct node *n)
{
	if (n==NULL)
		return 0;
	else{
		int lheight=height(n->lchild);
		int rheight=height(n->rchild);
		if (lheight>rheight)
			return lheight+1;
		else
			return rheight+1;
	}
}
int getMaxWidth(struct node *root)
{
	int i, width, maxWidth=0, h=height(root);
	for (i=1; i<=h; i++){
		width=getWidth(root, i);
		if (width>maxWidth)
			maxWidth=width;
	}
	return maxWidth;
}
int main()
{
	struct node *root=NULL, *p;
	int a[12]={1,13,14,25,69,70,4,5,6,7,9,10}, i, ch, data, width;
	
	//create and insert
	for (i=0; i<12; i++)
		root=insert(root, a[i]);
	printf("Inorder traversal: ");
	inorder(root);
	printf("\n");
	while (1){
		printf("\n1.Insert a node\n");
		printf("2. Delete an existing node\n");
		printf("3. Search for a node\n");
		printf("4. Search for largest element\n");
		printf("5. Search for smallest element\n");
		printf("6. Descending order of nodes in tree\n");
		printf("7. Display width of tree\n");
		printf("8. Quit\n");
		printf("\nEnter your choice:");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("Enter element: ");
				scanf("%d", &data);
				root=insert(root, data);
				printf("Inorder traversal of tree after insertion: ");
				inorder(root);
				printf("\n");
				break;
			case 2:
				printf("Enter element to be deleted: ");
				scanf("%d", &data);
				root=del(root, data);
				printf("Inorder traversal of tree after deletion: ");
				inorder(root);
				printf("\n");
				break;
			case 3:
				printf("Enter element to be searched:");
				scanf("%d", &data);
				p=search(root, data);
				if(p==NULL)
					printf("Node is not present\n");
				else
					printf("Node is present\n");
				break;
			case 4:
				p=max(root);
				if (p!=NULL)
					printf("Node with highest value: %d\n", p->info);
				break;
			case 5:
				p=min(root);
				if (p!=NULL)
					printf("Node with lowest value: %d\n", p->info);
				break;
			case 6:
				printf("Descending order: ");
				descending(root);
				printf("\n");
				break;
				
			case 7:
				printf("Width of tree: %d\n", getMaxWidth(root));
				break;
				
			case 8:
				exit(1);
				
			default:
				printf("Wrong choice");		
		}
	}
	return 0;
}
