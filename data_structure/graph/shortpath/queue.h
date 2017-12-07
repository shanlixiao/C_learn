#include <stdio.h>
#include <stdlib.h>
#define MAXQSIZE 100
typedef struct{
//动态分配存储空间
  int *base;
  //头指针
  int front;
  //尾指针
  int rear;
}SqQueue;

int InitQueue(SqQueue &Q){
  Q.base = (int *)malloc(MAXQSIZE * sizeof(int));
  if(!Q.base) exit(1);
  Q.front = Q.rear;
  return 1;
}

int Queuelength(SqQueue &Q){
  //返回Q元素个数
  return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

int DeQueue(SqQueue &Q,int &e){
  if(Q.front == Q.rear) return 0;
  e = Q.base[Q.front];
  Q.front = (Q.front + 1) % MAXQSIZE;
  return 1;
}

int EnQueue(SqQueue &Q,int e){
  if((Q.rear + 1) % MAXQSIZE == Q.front) return 0;
  Q.base[Q.rear] = e;
  Q.rear = (Q.rear + 1) % MAXQSIZE;
  return 1;
}

int PrintQ(SqQueue &Q){
  int p;
  p = Q.front;
  while(p != Q.rear){
    printf("%d\t",Q.base[p]);
    p = (p + 1) % MAXQSIZE;
  }
  return 1;
}
int is_Empty(SqQueue &Q){
  return Q.front == Q.rear;
}
