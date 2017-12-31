#include <stdio.h>
#include <string.h>
#include <cstdlib>
#define ERROR -1;
#define OK 1;
typedef struct node
{
    int data;
    struct node *next;
}Lnode,*Linklist;

int List_Insert(Linklist &L,int i,int e)
{
    Linklist p,s;
    p = L;
    int j = 0;
    while(p->next && j < i - 1)
    {
        p = p ->next;
        ++j;
    }
    if(!(p->next) || j > i - 1) return ERROR;
    s = (Linklist)malloc(sizeof(Lnode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 1;
}
int List_Delete_Pos(Linklist &L,int i)
{
    Linklist p,q;
    p = L;
    int j,e ;
    j = 0;
    while(p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if(!(p->next) || j > i - 1) return ERROR;
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);
    return 1;
}
void List_Show_All(Linklist &L)
{
    Linklist p;
    p = L;
    while(p->next)
    {
        p = p->next;
        printf("%d\t",p->data);
    }
    printf("\n");
}

void List_Create_order(Linklist &L,int n)
{
    int i;
    printf("输入链表长:\n");
    scanf("%d",&n);
    Linklist p,t;
    L = (Linklist)malloc(sizeof(Lnode));
    L->next = NULL;
    t = L;
    printf("输入链表内容·:\n");
    for(i = n;i >0;i--)
    {
        p = (Linklist)malloc(sizeof(Lnode));
        scanf("%d",&p->data);
        p->next = NULL;
        t->next = p;
        t = p;
    }
}
int main()
{
    Linklist L;
    int n;
    List_Create_order(L,n);
    printf("现在开始插入元素\n");
    int i,e;
    printf("请输入你想插入的元素位置：");
    scanf("%d",&i);
    printf("请输入你想在该位置插入的元素：");
    scanf("%d",&e);
    List_Insert(L,i,e);
    int j;
    printf("现在开始按元素位置删除\n");
    printf("请输入你想删除的元素位置：");
    scanf("%d",&j);
    List_Delete_Pos(L,j);
    List_Show_All(L);
    
}
