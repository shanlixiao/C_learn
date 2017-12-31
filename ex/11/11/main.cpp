#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
}*link,node;

int create(link &L,int n)
{
    int i;
    L = (link)malloc(sizeof(node));
    link p,t;
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
    int i;
    link p = L;
    while(p->next != NULL)
    {
        p = p->next;
        printf("%d\t",p->data);
    }
    printf("\n");
    return 0;
}
int connect(link &L,link &M,int a,int b)
{
    link p = L;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = M->next;
    return 0;
}
int main()
{
    int a,b;
    printf("input the a and b:");
    scanf("%d%d",&a,&b);
    link L,M;
    create(L,a);
    create(M,b);
    show(L,a);
    show(M,b);
    connect(L,M,a,b);
    show(L,a+b);
}
