#include "mazepath.h"
int main()
{
  array a;
  Pos start,end;
  int x,y,m,n;
  input(a);
  printf("Please input the start and end:");
  scanf("%d%d%d%d",&x,&y,&m,&n);
  start.x = x;
  start.y = y;
  end.x = m;
  end.y = n;
  mazepath(a,start,end);
}
