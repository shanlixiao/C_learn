#include <stdio.h>
#include <stdlib.h>
#include "head.h"

void Create(MGraph &G){
  FILE *fp;
  int i,j;
  if((fp = fopen("data.txt","r")) == NULL)
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


void ShortPath_floyd(MGraph G,ShortPathTable2 (*D)[20],PathMatrix3 (*p)[20][20])
{
  int i,j,u,v;
  for(i = 0;i < G.vexnum;++i)
  {
    for(j = 0;j < G.vexnum;++j)
    {
      **D[i][j] = G.arcs[i][j].adj;
      for(u = 0;u < G.vexnum;++u)
      {
        ***p[i][j][u] = 0;
      }
      if(**D[i][j] < INFINITY){
        ***p[i][j][i] = 1;
        ***p[i][j][j] = 1;
      }
    }
  }

  for(u = 0;u < G.vexnum;++u)
    for(i = 0;i < G.vexnum;++i)
      for(j = 0;j < G.vexnum;++j)
      {
        if(**D[i][u] + **D[u][j] < **D[i][j])
        {
          **D[i][j] = **D[i][u] + **D[u][j];
          for(v = 0;v < G.vexnum;++v)
          {
            ***p[i][j][v] = ***p[i][u][v] || ***p[u][j][v];
          }
        }

      }
}

int main()
{
  MGraph G;
  PathMatrix3 p3[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];
  ShortPathTable2 D2[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
  Create(G);
  // ShortPath_floyd(G,D2,p3);
}
