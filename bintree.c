#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *lc;
    struct node *rc;
};
struct node * inpred(struct node *ptr){
    struct node *p=ptr;
    p=p->lc;
    while(p->lc!=NULL){
        p=p->rc;
    }
    return p;
}
struct node * insucc(struct node *ptr){
    struct node *p=ptr;
    p=p->rc;
    while(p->lc!=NULL){
        p=p->lc;
    }
    return p;
}
void inorder(struct node *root){
    struct node *p=root;
    if(p==NULL){
        return;
    }
    inorder(p->lc);
    printf("%d ",p->info);
    inorder(p->rc);
}
struct node * insert(struct node *root,int ikey){
    struct node *temp,*p,*par=NULL;
    int found=0;
    p=root;
    while(p!=NULL){
        if(p->info==ikey){
            found=1;
            break;
        }
        par=p;
        if(ikey<p->info){
            if(p->lc!=NULL){
                p=p->lc;
            }
            else{
                break;
            }
        }
        else if(ikey>p->info){
            if(p->rc!=NULL){
                p=p->rc;
            }
            else{
                break;
            }
        }
    }
    if(found==1){
        printf("\nKey already exists");
    }
    else{
        temp=(struct node *)malloc(sizeof(struct node));
        temp->info=ikey;
        temp->lc=NULL;
        temp->rc=NULL;
        if(par==NULL){
            root=temp;
        }
        else if(ikey<par->info){
            par->lc=temp;
        }
        else if(ikey>par->info){
            par->rc=temp;
        }
    }
    return root;
}
struct node * caseA(struct node *par,struct node *p,struct node *root){
    if(par==NULL){
        root=NULL;
    }
    else if(par->info>p->info){
        par->lc=NULL;
    }
    else{
        par->rc=NULL;
    }
    free(p);
    return root;
}
struct node * caseB(struct node *par,struct node *p,struct node *root){
    struct node *child,*s,*pr;
    if(p->lc!=NULL){
        child=p->lc;
    }
    else if(p->rc!=NULL){
        child=p->rc;
    }
    if(par==NULL){
        root=child;
    }
    else if(par->info>p->info){
        par->lc=child;
    }
    else if(par->info<p->info){
        par->rc=child;
    }
    free(p);
    return root;
}
struct node * caseC(struct node *par,struct node *p,struct node *root){
    struct node *parsucc,*succ;
    succ=p->rc;
    parsucc=p;
    while(succ->lc!=NULL){
        parsucc=succ;
        succ=succ->lc;
    }
    p->info=succ->info;
    if(succ->lc==NULL && succ->rc==NULL){
        root=caseA(parsucc,succ,root);
    }
    else{
        root=caseB(parsucc,succ,root);
    }
    return root;
}
struct node * del(struct node *root,int dkey){
    struct node *temp,*par,*p;
    p=root,par=NULL;
    int found=0;
    while(p!=NULL){
        if(dkey==p->info){
            found=1;
            break;
        }
        par=p;
        if(dkey<p->info){
            if(p->lc!=NULL){
                p=p->lc;
            }
            else{
                break;
            }
        }
        if(dkey>p->info){
            if(p->rc==NULL){
                p=p->rc;
            }
            else{
                break;
            }
        }
    }
    if(found==0){
        printf("%d is not present in tree",dkey);
    }
    else{
        if(p->lc!=NULL && p->rc!=NULL){
            root=caseC(par,p,root);
        }
        else if(p->lc!=NULL){
            root=caseB(par,p,root);
        }
        else if(p->rc!=NULL){
            root=caseB(par,p,root);
        }
        else{
            root=caseA(par,p,root);
        }
    }
    return root;
}
void search(struct node *root,int skey){
    struct node *p=root;
    int found=0;
    if(p==NULL){
        return 0;
    }
    while(p!=NULL){
        if(p->info==skey){
            found=1;
            break;
        }
        if(skey<p->info){
            if(p->lc!=NULL){
                p=p->lc;
            }
            else{
                break;
            }
        }
        if(skey>p->info){
            if(p->rc!=NULL){
                p=p->rc;
            }
            else{
                break;
            }
        }
    }
    if(found==1){
        printf("\nKey is present in tree");
    }
    else{
        printf("\nKey is not present in tree");
    }
}
int main(){
    struct node *root=NULL;
    int arr[7]={5,3,4,2,7,6};
    int i;
    for(i=0;i<6;i++){
        root=insert(root,arr[i]);
    }
    int ch,n,dn,sn;
    while(1){
        printf("\n1.Insert a node\n2.Inorder Traversal\n3.Delete a node\n4.Search for a node\n5.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case(1):
                printf("\nEnter key:");
                scanf("%d",&n);
                root=insert(root,n);
                break;
            case(2):
                inorder(root);
                break; 
            case(3):
                printf("\nEnter key to be deleted:");
                scanf("%d",&dn);
                root=del(root,dn);
                break;
            case(4):
                printf("\nEnter key to be searched for in tree:");
                scanf("%d",&sn);
                search(root,sn);
                break;
            case(5):
                exit(0);
        }
    }
}
