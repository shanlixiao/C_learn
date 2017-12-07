#include <stdio.h>
#include <cstdlib>
#define OVERFLOW 0
enum PointerTag{link,Thread};
//输出元素e
int visit(char e)
{
  if(e){
      printf("%c\t",e);
      return 1;
  }
  else return 0;

  return 1;
}

typedef struct node{
  int data;
  struct node *lchild,*rchild;
  int ltag,rtag;
}*TBTNode;

int CreateBiTree(TBTNode *T){
  char ch;
  scanf("%c",&ch);
  if(ch == '0') T = NULL;
  else {
    *T = (TBTNode)malloc(sizeof(TBTNode));
    if(!(*T)) exit(OVERFLOW);
    if(*T == NULL) return 0;
    (*T)->data = ch;
    CreateBiTree(&((*T)->lchild));
    CreateBiTree(&((*T)->rchild));
    return 0;
  }
  return 0;

}


void InThreading(TBTNode *p)
{
  TBTNode *pre;
  if(p)
  {
    InThreading(p->lchild);
    if(!p->lchild)
    {
      p->lchild = pre;
      p->ltag = Thread;
    }
    if(!pre->rchild)
    {
      pre->rchild = p;
      pre->rtag = link;
    }
    pre = p;
    InThreading(p->rchild);
  }
}

int InOrderThreading(TBTNode *p,TBTNode *T)
{
  TBTNode *pre,*Thrt;
  if(!(Thrt = (TBTNode *)(malloc(sizeof(TBTNode))))) exit(OVERFLOW);
  Thrt->ltag = link;
  Thrt->rtag = Thread;
  Thrt->rchild = Thrt;
  // if(!T) Thrt->lchild = Thrt;
  // if(&T)
  // {
    Thrt->lchild = T;
    pre = T;
    InThreading(T);
    pre->rtag = Thread;
    pre->rchild = Thrt;
    Thrt->rchild = pre;
  // }
  return 0;
}

int InOrderTraverse(TBTNode *T)
{
  TBTNode *p;
  p = T->lchild;
  if(T){
    while(p!=T)
    while(p->ltag == link) p = p->lchild;
    if(!visit(p->data)) return 0;
    while(p->rtag == Thread)
    {
      p = p->rchild;
      visit(p->data);
    }
    p = p->rchild;
  }
  return 0;
}
//
// int main()
// {
//     TBTNode *T,*S;
//     CreateBiTree(T);
//     InOrderThreading(S,T);
//     InOrderTraverse(S);
//
// }

// int perOrderTracerse(TBTNode *T){
//   if(*T){
//     if(visit((*T)->data))
//       if(perOrderTracerse(&(*T)->lchild))
//         if(perOrderTracerse(&(*T)->rchild)) return 1;
//     return 0;
//   }
//   else return 1;
// }
int main()
{
  TBTNode T,temp;
  CreateBiTree(T,temp);
  InOrderThreading(&temp,T);
  InOrderTraverse(&T);
  // printf("%d",T->lchild->data);
  return 0;
}
//
