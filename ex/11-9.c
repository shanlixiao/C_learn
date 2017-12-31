#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int data;
  struct node *next;
}*link,node;

int create(link L,int n)
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
  printf("%d",p->data);
  while(p->next != NULL)
  {
    printf("%d",p->data);
    p = p->next;
  }
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
    printf("hello");
    show(L,a);
}
