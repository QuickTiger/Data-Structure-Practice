#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SCALE 5000000
int m=0,n=0;
int A[SCALE];
typedef struct Node
{
    int left;
    int right;
    struct Node *next;
}Node;
void Swap(int *A ,int *B){int tmp;tmp=*A;*A=*B;*B=tmp;}
void Link_Push(Node *Link,int left ,int right)
{
    Node *pa=Link;
    while(pa->next!=NULL){pa=pa->next;}
    pa->next=malloc(sizeof(Node));
    pa=pa->next;pa->next=NULL;
    pa->left=left;pa->right=right;
    m++;
}
Node* Link_Pop(Node *Link )
{
    Node *pa,*result;
    pa=Link;
    if (pa->next==NULL){return NULL;}
    while(pa->next->next!=NULL){pa=pa->next;}
    result=pa->next;pa->next=NULL;
    n++;
    return result;
}

void QSort_Stack(int A[],int left ,int right)
{
    int i,j;
    Node *pa;
    Node *A_Link=malloc(sizeof(Node));
    A_Link->left=-1;A_Link->right=-1;A_Link->next=NULL;
    Link_Push(A_Link,left,right);
    while(A_Link->next!=NULL)
    {
        pa=Link_Pop(A_Link);
        if (pa->left<pa->right)
        {
            i=pa->left;j=pa->right+1;
            do
            {
                do i++; while(A[i]<A[pa->left]);
                do j--; while(A[j]>A[pa->left]);
                if(i<j)Swap(&A[i],&A[j]);
            }while(i<j);
            Swap(&A[pa->left],&A[j]);
            Link_Push(A_Link,pa->left,j-1);
            Link_Push(A_Link,j+1,pa->right);
        }
        free(pa);
    }
}
int main()
{
    int i;
    for (i=0;i<SCALE;i++){A[i]=rand();}
    long t_s = clock();
    QSort_Stack(A,0,sizeof(A)/sizeof(int)-1);
    long t_e =clock();
  //  for(i=0;i<sizeof(A)/sizeof(int);i++){printf("%d\n",A[i]);}
    printf("%f\n",(float)(t_e-t_s)/1000);
    printf("POP : %d\n",n++);
    printf("Push : %d\n",m++);
    return 0;
}
