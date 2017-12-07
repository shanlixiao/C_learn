#include <stdio.h>
#include <cstdlib>
#include <string.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int array[100][100];
typedef struct {
  int x; //x axis
  int y; //y axis
  int z; //表示是否走过
  int di;//方向
}Pos1;
typedef struct {
  int x; //x axis
  int y;
}Pos;

typedef struct {
  Pos1 *base;
  Pos1 *top;
  int stacksize;
}SqStack;
int StackEmpty(SqStack &S)
{
  if (S.top == S.base)
  return 1;
  else return 0;
}
int Init(SqStack &S)
{
  S.base = (Pos1 *)malloc(STACK_INIT_SIZE *sizeof(int));
  if (!S.base) return 0;
  S.top = S.base;
  S.stacksize = STACK_INIT_SIZE;
  return 1;
}//Init

int Push(SqStack &S,Pos1 e)
{
  if(S.top - S.base >= S.stacksize){
    S.base = (Pos1 *)realloc(S.base,(S.stacksize + STACKINCREMENT)*sizeof(int));
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

int getTop(SqStack S,Pos1 &cur)
{
  cur = *(S.top - 1);
  return 0;
}
