#include <stdio.h>
#include <stdlib.h>
#include "head1.h"

void Create(MGraph &G){
  FILE *fp;
  int i,j;
  if((fp = fopen("data1.txt","r")) == NULL)
  {
    printf("can not open the file!\n");
    exit(0);
  }
  printf("Please input the vexnum:\n");
  printf("vexnum:");
  scanf("%d",&G.vexnum);
  for(i = 0;i < G.vexnum;++i)
  {
    for(j = 0;j < G.vexnum;++j)
    {
      fscanf(fp,"%d ",&G.arcs[i][j].adj);
    }
  }
  for(i = 0;i < G.vexnum;++i)
  {
    for(j = 0;j < G.vexnum;++j)
    {
      printf("%d ",G.arcs[i][j].adj);
    }
    printf("\n");
  }
    fclose(fp);
  // printf("aaaa");
}
void ShortPathTable_DIJ(MGraph G,int v0,PathMatrix (*p)[20],ShortPathTable *D){
  //p[v][w] = 1:表示最短路径从v0到v经过w
  //D[v]:v0到v最短带权长度
  int v,w;
  int final[MAX_VERTEX_NUM];
  for(v = 0;v < G.vexnum;++v){
    final[v] = 0;
    //初始长度
    *D[v] = G.arcs[v0][v].adj;
    for(w = 0;w < G.vexnum;++w){
      //空路径
      **p[v][w] = 0;
    }
    if(*D[v] < INFINITY){
      //最短路径包括起始点和终点
      **p[v][v0] = 1;
      **p[v][v] = 1;
    }
  }
  *D[v0] = 0;
  final[v0] = 1;

  int i;
  for(i = 1;i < G.vexnum;++i){
    int min = INFINITY;
      for(w = 0;w < G.vexnum;++w)
      if(!final[w]){
        if(*D[w] < min){
          min = *D[w];
          v = w;
        }
    }
    //v0到v找到最短路径
    final[v] = 1;
    for(w = 0;w < G.vexnum;++w){
      if(!final[w] && min + G.arcs[v][w].adj < *D[w]){
        *D[w] = min + G.arcs[v][w].adj;
        int i;
        for(i = 0;i < G.vexnum;++i)
        {
            **p[w][i] = **p[v][i];
        }

        **p[w][v] = 1;
        **p[w][w] = 1;
      }
    }
  }
}

void output(PathMatrix (*p)[20],ShortPathTable *D,MGraph G){
  int i,j;
  // printf("带权长度表:\n");
  for(i = 0;i < G.vexnum;++i){
    if(*D[i] > 0 && *D[i] < 1000)
    {
      printf("to the %d vertex,the shortest distence is:",i+1);
      printf("%d\n",*D[i]);
    }
  }
  // printf("路径矩阵:\n");

  for(i = 0;i < G.vexnum;++i){
    int k = 0;
    printf("to the %d vertex：\n",i+1);
    for(j = 0;j < G.vexnum;++j)
    {
      if(**p[i][j] > 0)
      {
        printf("%d ",j+1);
        ++k;
      }
    }
    if(k == 0)
    {
      printf("no path\n");
    }
    else printf("\n");
  }
  printf("\n");
}

int main()
{
  MGraph G;
  PathMatrix p[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
  ShortPathTable D[MAX_VERTEX_NUM];

  Create(G);
  int i;
  for(i = 0;i < G.vexnum;++i)
  {
    printf("从第%d个点出发寻找\n",i+1);
    ShortPathTable_DIJ(G,i,p,D);
    output(p,D,G);
  }
  return 0;
}
