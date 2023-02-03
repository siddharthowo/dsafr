#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct vertex;
struct edge{
    struct vertex *v;
    struct edge *ne;
};
struct vertex{
    struct vertex *nv;
    int info;
    struct edge *fe;
};
struct vertex *start=NULL;
struct vertex * addv(int item){
    struct vertex *temp,*p;
    temp=(struct vertex *)malloc(sizeof(struct vertex));
    temp->info=item;
    temp->fe=NULL;
    temp->nv=NULL;
    if(start==NULL){
        start=temp;
        return start;
    }
    else{
        p=start;
        while(p->nv!=NULL){
            p=p->nv;
        }
        p->nv=temp;
    }
    return start;
}
struct vertex * loc(int u){
    struct vertex *p=start;
    while(p!=NULL){
        if(p->info==u){
            return p;
        }
        p=p->nv;
    }
    return p;
}
void adde(int u,int v){
    struct vertex *p,*q;
    p=loc(u);
    q=loc(v);
    if(p!=NULL && q!=NULL){
        struct edge *temp,*t;
        temp=(struct edge *)malloc(sizeof(struct edge));
        temp->v=q;
        temp->ne=NULL;
        if(p->fe==NULL){
            p->fe=temp;
        }
        else{
            t=p->fe;
            while(t->ne!=NULL){
                t=t->ne;
            }
            t->ne=temp;
        }
    }
    else{
        printf("\nInvalid vertex entered");
    }
}
void deledge(int u,int v1){
    struct edge *temp,*q;
    struct vertex *p;
    p=loc(u);
    if(p->fe==NULL){
        printf("\nNo edges present");
        return;
    }
    if(p->fe->v->info==v1){
        temp=p->fe;
        p->fe=temp->ne;
        free(temp);
        printf("\nEdge deleted successfully");
        return;
    }
    else{
        q=p->fe;
        while(q->ne!=NULL){
            if(q->ne->v->info==v1){
                temp=q->ne;
                q->ne=temp->ne;
                free(temp);
                printf("\nEdge deleted successfully");
                return;
            }
            q=q->ne;
        }
        printf("\nEdge not present");
    }
}
void delvertex(int u){
    struct vertex *p,*temp;
    struct edge *q,*temp1;
    p=start;
    if(start==NULL){
        printf("\nNo vertices present");
        return;
    }
    else{
        if(start->info==u){
            temp=start;
            start=start->nv;
        }
        else{
            while(p->nv!=NULL){
                if(p->nv->info==u){
                    break;
                }
                p=p->nv;
            }
            if(p->nv==NULL){
                printf("\nVertex not present");
                return;
            }
            else{
                temp=p->nv;
                p->nv=temp->nv;
            }
            q=temp->fe;
            while(q!=NULL){
                temp1=q;
                q=q->ne;
                free(temp1);
            }
            free(temp);
        }
        return;
    }
}
void delincomingedges(int u){
    struct vertex *p;
    struct edge *q,*temp;
    p=start;
    while(p!=NULL){
        if(p->fe==NULL){
            p=p->nv;
            continue;
        }
        if(p->fe->v->info==u){
            temp=p->fe;
            p->fe=temp->ne;
            free(temp);
            continue;
        }
        q=p->fe;
        while(q->ne!=NULL){
            if(q->ne->v->info==u){
                temp=q->ne;
                q->ne=temp->ne;
                free(temp);
                continue;
            }
            q=q->ne;
        }
        p=p->nv;
    }
}
void display(){
    if(start==NULL){
        printf("\nNo vertices present");
        return;
    }
    struct vertex *p=start;
    struct edge *q;
    while(p!=NULL){
        printf("\n%d->",p->info);
        q=p->fe;
        while(q!=NULL){
            printf("%d",q->v->info);
            q=q->ne;
        }
        p=p->nv;
    }
}
int n=6;
int main(){
    int i;
    int vs,vd;
    int v;
    printf("\nEnter 6 vertices:");
    for(i=0;i<n;i++){
        printf("\nEnter vertex:");
        scanf("%d",&v);
        start=addv(v);
    }
    for(i=0;i<(n*n-1)/2;i++){
        printf("\nEnter vertices(-1 -1 to exit):");
        scanf("%d %d",&vs,&vd);
        if((vs==-1) && (vd==-1)){
            break;
        }
        else{
            adde(vs,vd);
            adde(vd,vs);
        }
    }
    printf("\nUndirected Graph is:");
    display();
    deledge(3,5);
    deledge(5,3);
    printf("\nGraph after deleting edge between 3 and 5:");
    display();
    delincomingedges(3);
    delvertex(3);
    printf("\nGraph after deleting vertex 3:");
    display();
    int sn;
    printf("\nEnter vertex to be searched:");
    scanf("%d",&sn);
    if(loc(sn)){
        printf("\nVertex Found!");
    }
    else{
        printf("\nVertex absent");
    }
}

