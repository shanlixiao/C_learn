#include "stackh.h"
void input(array &a)
{
  int n;
  int i,j;
  printf("Please input the row numbers:");
  scanf("%d",&n);
  for(i = 0;i < n;i++)
    for(j = 0;j < n;j++)
    {
      scanf("%d",&a[i][j]);
    }
}
void output(array a)
{
  int n;
  int i,j;
  printf("Please input the row numbers:");
  scanf("%d",&n);
  for(i = 0;i < n;i++)
    for(j = 0;j < n;j++)
    {
      printf("%d",a[i][j]);
    }
}
int mazepath(array &a,Pos start,Pos end)
{
  SqStack S;
  Pos1 cur;
  // int step;
  // step = 1;
  Init(S);
  cur.x = start.x;
  cur.y = start.y;

  do{
    //如果当前位置与终点位置相同，退出循环。
    if (cur.x == end.x && cur.y == end.y)
    {
      a[cur.x][cur.y] = 2;
      printf("找到通路！\n");
      Push(S,cur);
      break;
    }
    //如果当前位置值为0：
    if (a[cur.x][cur.y] == 0)
    {
      if (a[cur.x][cur.y+1] == 0 )
      {
        Push(S,cur);
        a[cur.x][cur.y] = 2;
        cur.y++; cur.di = 1;
      }
      else if (a[cur.x+1][cur.y] == 0)
      {
        Push(S,cur);
        a[cur.x][cur.y] = 2;
        cur.x++;
        cur.di = 2;
      }
      else if (a[cur.x][cur.y-1] == 0)
      {
        Push(S,cur);
        a[cur.x][cur.y] = 2;
        cur.y--; cur.di = 3;
      }
      else if (a[cur.x-1][cur.y] == 0)
      {
        Push(S,cur);
        a[cur.x][cur.y] = 2;
        cur.x--; cur.di = 4;
      }
      else
      {
        a[cur.x][cur.y] = 1;
        if(cur.di == 1) cur.y--;
        else if(cur.di == 2) cur.x--;
        else if(cur.di == 3) cur.y++;
        else cur.x++;
      }
    }
      //如果当前位置值为2:
      if(a[cur.x][cur.y] == 2)
      {
        if (a[cur.x][cur.y+1] == 0 )
        {
          cur.y++; cur.di = 1;
        }
        else if (a[cur.x+1][cur.y] == 0)
        {
          cur.x++;
          cur.di = 2;
        }
        else if (a[cur.x][cur.y-1] == 0)
        {
          cur.y--; cur.di = 3;
        }
        else if (a[cur.x-1][cur.y] == 0)
        {
          cur.x--; cur.di = 4;
        }
        else
        {
          Pop(S);
          a[cur.x][cur.y] = 1;
          if(cur.di == 1) cur.y--;
          else if(cur.di == 2) cur.x--;
          else if(cur.di == 3) cur.y++;
          else cur.x++;
        }
    }

  }while(!StackEmpty(S));
  if(StackEmpty(S))
  {
    printf("找不到通路!\n");
  }
  Pos1 n;
  SqStack K;
  Init(K);
  while(!StackEmpty(S))
  {
    getTop(S, n);
    Push(K,n);
    Pop(S);
  }
  int i = 1;
  while(!StackEmpty(K))
  {
    getTop(K, n);
    printf("第%d步：(%d,%d)\n",i,n.x,n.y);
    Pop(K);
    i++;
  }
  return 0;
}
