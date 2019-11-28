#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        int r,c;
        struct node *next,*prev;
};
struct node *start=NULL;
struct node *getnode()
{
        struct node *p;
        p=(struct node*)malloc(sizeof(struct node));
        p->next=NULL;
        p->prev=NULL;
        return p;
}
void creatematrix(int m,int n)
{
        int i,j,a;
        struct node *last=NULL;


        for(i=0;i<m;i++)

        {
                for(j=0;j<n;j++)
                {
                        printf("enter element a%d%d\n",i,j);

                        scanf("%d",&a);
                        if(a!=0)
                        {struct node *p;
                                p=getnode();
                                p->data=a;
                                p->r=i;
                                p->c=j;
                                if(start==NULL)
                                {
                                        start=p;
                                }
                                else
                                {struct node *q;
                                        q=start;
                                        while(q->next!=NULL)
                                        {q=q->next;
                                        }
                                        q->next=p;
                                        p->prev=q;
                                }

                        }
                }
        }
}
void displaymatrix(int m,int n)
{
        int i,j,zero=0;
        struct node *p;
        printf("\nthe sparce matrix is :\n");
        p=start;
        for(i=0;i<m;i++)
        {
                for(j=0;j<n;j++)
                {if(p!=NULL&&p->r==i&&p->c==j)
                        {
                        printf("%4d",p->data);
                        printf("\t");
                        p=p->next;
                        }
                        else{
                                printf("%4d",zero);
                                printf("\t");
                        }
                }
        }
}
int main()
{
        int m,n;
        printf("enter the order of matrix\n");
        scanf("%d%d",&m,&n);
        creatematrix(m,n);
                displaymatrix(m,n);
        return 0;
}

                                                       
