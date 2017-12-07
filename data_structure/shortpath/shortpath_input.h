#include "head.h"
void Create(MGraph &G){
  printf("Please input the vexnum and arcnum:\n");
  printf("vexnum:");
  scanf("%d",&G.vexnum);
  printf("arcnum:");
  scanf("%d",&G.arcnum);
  int i,j;
  for(i = 0;i < G.vexnum;++i)
    for(j = 0;j < G.vexnum;++j)
    {
      scanf("%d",&G.arcs[i][j].adj);
    }
}
