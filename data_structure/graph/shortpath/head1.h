#define INFINITY 1000
#define MAX_VERTEX_NUM 20
typedef struct ArcCell{
  int adj;
}AdjMatrix[20][20];

typedef struct{
  int vexs[20];
  AdjMatrix arcs;
  int vexnum,arcnum;
}MGraph;

typedef int PathMatrix[20][20];
typedef int ShortPathTable[20];
