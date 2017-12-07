#include <stdio.h>
#include <stdio.h>
#include "head.h"
// #include "file.c"
void Create(MGraph &G){
  FILE *fp;
  int i,j;
  int k = 1;
  if((fp = fopen("data.txt","r")) == NULL)
  {
    printf("can not open the file!\n");
    exit(0);
  }
  printf("Please input the vexnum and arcnum:\n");
  printf("vexnum:");
  scanf("%d",&G.vexnum);
  printf("h");
  for(i = 0;i < G.vexnum;++i)
  {
    printf("h\n");
    for(j = 0;j < G.vexnum;++j)
    {
      fscanf(fp,"%d ",&G.arcs[i][j].adj);
      printf("%d\n",k);
      ++k;
    }
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
        **p[w][v] = 1;
        **p[w][w] = 1;
      }
    }
  }
}

void output(PathMatrix (*p)[20],ShortPathTable *D,MGraph G){
  int i,j;
  printf("带权长度表:\n");
  for(i = 0;i < G.vexnum;++i){
    printf("%d ",*D[i]);
  }
  printf("\n");
  printf("路径矩阵:\n");
  for(i = 0;i < G.vexnum;++i){
    for(j = 0;j < G.vexnum;++j)
    {
      printf("%d ",**p[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  MGraph G;
  PathMatrix p[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
  ShortPathTable D[MAX_VERTEX_NUM];
  Create(G);
  ShortPathTable_DIJ(G,0,p,D);
  output(p,D,G);
  return 0;
}
