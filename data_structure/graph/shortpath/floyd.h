#include <stdio.h>
#include "head.h"
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
