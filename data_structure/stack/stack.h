#include <stdio.h>
#include <cstdlib>
#include <string.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct {
  int *base;
  int *top;
  int stacksize;
}SqStack;

int Init(SqStack &S)
{
  S.base = (int *)malloc(STACK_INIT_SIZE *sizeof(int));
  if (!S.base) return 0;
  S.top = S.base;
  S.stacksize = STACK_INIT_SIZE;
  return 1;
}//Init

int Push(SqStack &S,int e)
{
  if(S.top - S.base >= S.stacksize){
    S.base = (int *)realloc(S.base,(S.stacksize + STACKINCREMENT)*sizeof(int));
    if(!S.base) return 0;
    S.top = S.base + S.stacksize;
    S.stacksize += STACKINCREMENT;
  }//if
  *S.top = e;
  S.top++;
  return 1;
}//Push

int Pop(SqStack &S)
{
  if (S.top == S.base) return 0;
  --S.top;
  return 1;
}

int getTop(SqStack S)
{
  return *(S.top - 1);
}
