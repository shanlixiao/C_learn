#include <stdio.h>
#include <stdlib.h>
#define INFINTY INT_MAX
#define MAX_VERTEX_NUM 20
// typedef enum {DG,DN,UDG,UDN} GraphKind;
typedef struct ArcNode{
  int adjvex;
  struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
  int data;
  ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct {
  AdjList vertices;
  int vexnum,arcnum;
  int kind;
}ALGraph;

void AddNode(ALGraph &G,int v,int w){
  G.vertices[v].data = v;
  if(G.vertices[v].firstarc == NULL){
    G.vertices[v].firstarc = (ArcNode *)malloc(sizeof(ArcNode));
    G.vertices[v].firstarc->adjvex = w;
	  G.vertices[v].firstarc->nextarc = NULL;
	  return;
  }
  ArcNode *p = G.vertices[v].firstarc;
  while(p->nextarc != NULL){
	  p = p->nextarc;
}
  ArcNode* move = (ArcNode *)malloc(sizeof(ArcNode));
  move->adjvex = w;
  move->nextarc = NULL;
  p->nextarc = move;
  // move = move->nextact;
}

void visit(int data){
	printf("%d->",data);
}

void input(ALGraph &G){
  /*FILE *fp;
    fp = fopen("data.txt","r");
  if(fp == NULL)
  {
    printf("can not open the file\n");
    exit(0);
  }
*/
  for(int i = 0;i < MAX_VERTEX_NUM;++i)
  {
    G.vertices[i].firstarc = NULL;
  }
//	fscanf(fp,"%d %d ",&G.vexnum,&G.arcnum);
  printf("The vexnum and arcnum:\nvexnum:%d\narcnum:%d\n",G.vexnum,G.arcnum);
    scanf("%d%d",&G.vexnum,&G.arcnum);
	int i,v,w;
	for(i = 0;i < G.arcnum;++i){
		scanf("%d %d",&v,&w);
    printf("%d %d\n",v,w);
		AddNode(G,v,w);
		AddNode(G,w,v);
	}
}

int FirstAdjVex(ALGraph &G,int v){
  if(G.vertices[v].firstarc != NULL){
    return G.vertices[v].firstarc->adjvex;
  }
  else return -1;
}

int NextAdjVex(ALGraph G,int v,int w){
  if(G.vertices[v].firstarc != NULL){
    ArcNode *temp = G.vertices[v].firstarc;
    while(temp != NULL){
      if(temp->adjvex == w){
        if(temp->nextarc != NULL)
        {
          return temp->nextarc->adjvex;
        }
        else return -1;
      }
      temp = temp->nextarc;
    }
    return -1;
  }
  else return -1;
}
