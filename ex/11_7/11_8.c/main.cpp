#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}*link,node;

int insert(link &L,int e,int a)
// a is the insert node data
{
    link p = L;
    while(p->next && p->next->data != e)
    {
        p = p->next;
    }
    link q;
    q = (link)malloc(sizeof(node));
    q->data = a;
    q->next = p->next;
    p->next = q;
    return 0;
}

int create(link &L,int n)
{
    int i;
    link p,t;
    L = (link)malloc(sizeof(node));
    t = L;
    for(i = 0;i < n;++i)
    {
        p = (link)malloc(sizeof(node));
        scanf("%d",&p->data);
        p->next = NULL;
        t->next = p;
        t = p;
    }
    return 0;
}
int show(link L,int n)
{
    link p = L;
    while(p->next)
    {
        printf("%d\t",p->next->data);
        p = p->next;
    }
    return 0;
}
int main()
{
    link L;
    int n;
    printf("input the number:");
    scanf("%d",&n);
    create(L,n);
    int a,e;
    printf("please input the data that you want to insert:");
    scanf("%d",&a);
    printf("insert at the data:");
    scanf("%d",&e);
    insert(L,e,a);
    show(L,n);
}
