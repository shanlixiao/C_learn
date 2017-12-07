#include <stdio.h>
#include <cstdlib>
typedef struct Linknode{
  int data;
  struct Linknode *next;
}Linknode,*Linklist;

//逆序建循环链表
void Linklist_Create_inverse(Linklist &L,int n)
{
  int i;
  printf("请输入链表的元素个数：");
  scanf("%d",&n);
  Linklist p;
  L = (Linklist)malloc(sizeof(Linknode));
  L->next = NULL;
  for(i = n;i > 0;i--)
  {
    p = (Linklist)malloc(sizeof(Linknode));
    scanf("%d",&p->data);
    p->next = L->next;
    L->next = p;
  }
}

//按顺序建循环链表
void Linklist_Create_Order(Linklist &L,int n)
{
  int i;
  Linklist p,t;
  L = (Linklist)malloc(sizeof(Linknode));
  L->next = L;
  t = L;

  p = (Linklist)malloc(sizeof(Linknode));
  scanf("%d",&p->data);
  L->data = p->data;
  L->next = L;

  for(i = n - 1;i > 0;i--)
  {
    p = (Linklist)malloc(sizeof(Linknode));
    scanf("%d",&p->data);
    p->next = L;
    t->next = p;
    t = p;
  }
}

void Linklist_Inverse(Linklist &L)
{
  Linklist p,q,t;
  int n;
  p = L;
  t = L;
  t->next = L;
  while(p->next != L)
  {
    p = p->next;
    n++;
  }
  while(n)
  {
    q = p;
    q->next = t->next;
    t->next = q;
    p = p->next;
    n--;
  }
  L = t;
}

//显示表内容
void Linklist_Show(Linklist L)
{
  Linklist p;
  p = L;
  printf("Show linklist:\n");
  printf("%d\t",p->data);
  while(p->next != L)
  {
    p = p->next;
    printf("%d\t",p->data);
  }
  printf("\n");
}

int JoseDelete(Linklist &L, int M, int k)
{   int i;
    Linklist p = L,q;
    while(M>1)
    {
        for(i=1;i<k-1;i++)
        {
            p=p->next;
        }

        q=p->next;
        p->next=q->next;
        printf("出局的人为：%d号\n",q->data);
        free(q);

        p=p->next;
        M--;
    }
    printf("***************获胜者为：%d号***************\n",p->data);
    return 1;
}

void Joph(Linklist &L,int m)
{
  printf("处决第几个人？\n");
  int n;
  scanf("%d",&m);
  printf("有几个人参与？\n");
  scanf("%d",&n);
  Linklist p,q;
  p = L;
  while(n - 1)
  {
    while(m - 1)
    {
      p = p->next;
      m--;
    }
    q = p->next;
    printf("%d\t",q->data);

    p->next = q->next;
    p = p->next;
    n--;
  }
}
int main()
{
  int K,M;
  printf("处决第几个人？\n");
  scanf("%d",&K);
  printf("有几个人参与？\n");
  scanf("%d",&M);
  Linklist L;
  int n,m;
  Linklist_Create_Order(L,M);
  Linklist_Show(L);
  JoseDelete(L,M,K);
}
