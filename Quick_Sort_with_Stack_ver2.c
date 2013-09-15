#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SCALE 50000000
int m=0,n=0;
int A[SCALE];
typedef struct Node
{
    int left;
    int right;
    struct Node *next;
}Node;
void Swap(int *A ,int *B){int tmp;tmp=*A;*A=*B;*B=tmp;}
void QSort_Stack(int A[],int left ,int right)
{
    int i,j;
    Node *pa,*pa1;
    Node *A_Link=malloc(sizeof(Node));
    A_Link->left=-1;A_Link->right=-1;
    A_Link->next=malloc(sizeof(Node));
    A_Link->next->left=left;
    A_Link->next->right=right;
    A_Link->next->next=NULL;

    while(A_Link->next!=NULL)
    {
      //POP
        pa=A_Link;
        while(pa->next->next!=NULL){pa=pa->next;}
        pa1=pa;pa=pa->next;pa1->next=NULL;
        n++;
     //End POP
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
            //PUSH left
            pa1->next=malloc(sizeof(Node));
            pa1=pa1->next;
            pa1->left=pa->left;pa1->right=j-1;
            pa1->next=NULL; m++;
            //PUSH right
            pa1->next=malloc(sizeof(Node));
            pa1=pa1->next;
            pa1->left=j+1;pa1->right=pa->right;
            pa1->next=NULL; m++;
            //End PUSH
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
    printf("Time Consumed is : %f\n",(float)(t_e-t_s)/1000);

    return 0;
}
