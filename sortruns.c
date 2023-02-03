#include<stdio.h>
#include<stdlib.h>
#define MAX 30
void selsort(int a[],int size){
    int i,j,temp;
    int small;
    for(i=0;i<size;i++){
        small=i;
        for(j=i+1;j<size;j++){
            if(a[small]>a[j]){
                small=j;
            }
        }
        temp=a[i];
        a[i]=a[small];
        a[small]=temp;
    }
}
void display(int a[],int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
}
void bubblesort(int a[],int size){
    int i,j,c,temp;
    for(i=0;i<size;i++){
        c=0;
        for(j=0;j<size-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            c+=1;
        }
        if(c==0){
            break;
        }
    }
}
void insertsort(int a[],int size){
    int i,j,k;
    for(i=1;i<size;i++){
        k=a[i];
        for(j=i-1;j>=0 && k<a[j];j--){
            a[j+1]=a[j];
        }
        a[j+1]=k;
    }
}
void descbubble(int a[],int size){
    int i,j,c,temp;
    for(i=0;i<size;i++){
        c=0;
        for(j=size-1;j>i;j--){
            if(a[j-1]<a[j]){
                temp=a[j-1];
                a[j-1]=a[j];
                a[j]=temp;
            }
            c+=1;
        }
        if(c==0){
            break;
        }
    }
}
void shellsort(int a[],int n){
    int i,j,incr,k;
    printf("\nEnter increment value:");
    scanf("%d",&incr);
    while(incr>=1){
        for(i=incr;i<n;i++){
            k=a[i];
            for(j=i-incr;j>=0 && a[j]>k;j-=incr){
                a[j+incr]=a[j];
            }
            a[j+incr]=k;
        }
        incr-=2;
    }
}
void merge(int a[],int temp[],int low1,int up1,int low2,int up2){
    int i=low1,j=low2,k=low1;
    while(i<=up1 && j<=up2){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }
    while(i<=up1){
        temp[k++]=a[i++];
    }
    while(j<=up2){
        temp[k++]=a[j++];
    }
}
void copy(int a[],int temp[],int low,int up){
    int i;
    for(i=low;i<=up;i++){
        a[i]=temp[i];
    }
}
void mergesort(int a[],int low,int up){
    int mid;
    int temp[MAX];
    if(low<up){
        mid=(low+up)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,up);
        merge(a,temp,low,mid,mid+1,up);
        copy(a,temp,low,up);
    }
}
int main(){
    int size=5,ele;
    int i;
    int a[size];
    for(i=0;i<size;i++){
        printf("\nEnter integer:");
        scanf("%d",&ele);
        a[i]=ele;
    }
    printf("\nUnsorted list:");
    display(a,size);
    mergesort(a,0,size-1);
    printf("\nSorted list:");
    display(a,size);
}