#include <stdio.h>
#include "queue.h"
#include "head.h"
#define MAX 20

int visited[MAX];
void (* VisitFunc)(int v);

void DFS(ALGraph G,int v){
	int w;
	visited[v] = 1;
	VisitFunc(v);
	for(w = FirstAdjVex(G,v);w >= 0;w = NextAdjVex(G,v,w))
		if(!visited[w]) DFS(G,w);
}

void DFSTraverse(ALGraph &G,void (* visit)(int v)){
	VisitFunc = visit;
	int v;
	for(v = 0;v < G.vexnum;++v) visited[v] = 0;
	for(v = 0;v < G.vexnum;++v)
	{
		if(!visited[v]) DFS(G,v);
	}
	printf("\b\b  \n");
}




void BFS(ALGraph G,void (*visit)(int v),int begin)
{
	for(int v = 0;v < G.vexnum;++v)
	{
		visited[v] = 0;
	}
	SqQueue Q;
	InitQueue(Q);
	for(int v = begin;v < G.vexnum;++v)
	{
		if(!visited[v])
		{
			visited[v] = 1;
			visit(v);
			EnQueue(Q,v);
			while(!is_Empty(Q))
			{
				int u = -1;
				DeQueue(Q,u);
				for(int w = FirstAdjVex(G,u);w >= 0;w = NextAdjVex(G,u,w))
				{
					if(!visited[w])
					{
						visited[w] = 1;
						visit(w);
						EnQueue(Q,w);
					}
				}
			}
		}
	}
	printf("\b\b  ");
	printf("\n");
}
int main(){
	ALGraph G;
	input(G);
	int begin;
	printf("Where are you want to begin?\n");
	scanf("%d",&begin);
	printf("BFS traverse:");
	BFS(G,visit,begin);
	// printf("DFS traverse:");
	// DFSTraverse(G,visit);
	return 0;
}
