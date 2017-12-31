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

int Delete(link L,int n)
{
  link p,q;
  q = p = L;
  while(q->next != NULL)
  {
    q = q->next;
    p = q;
    while(p->next != NULL)
    {
      if(p->next->data == q->data)
      {
        p->next = p->next->next;
      }
      p = p->next;
    }
  }
    return 0;
}

int main()
{
  link L;
  int a;
  printf("input the a:");
  scanf("%d",&a);
  create(L,a);
  show(L,a);
  Delete(L,a);
  show(L,a);
}
