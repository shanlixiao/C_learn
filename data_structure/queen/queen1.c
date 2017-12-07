#include <stdio.h>
#include <stdlib.h>
int a[100];
int isvalid(int k)
{
  int i;
  for(i = 1;i < k;i++)
  {
    //判断第一个至第k个皇后是否冲突
    if(a[i] == a[k] || abs(a[i] - a[k]) == abs(i - k))
      return 0;
  }
  return 1;
}
void queen()
{
  int k,i,j = 0;
  //皇后都在0处
  for(i = 1;i <= 8;i++)
  {
    a[i] = 0;
  }
  k = 1;
  while(k > 0)
  {
    //将当前皇后右移一位
    a[k] += 1;
    //如果皇后冲突且所处位置在1-8以内，右移一位
    while(!isvalid(k) && a[k] <= 8)
      a[k] += 1;
    //如果第八个皇后位置移动好，输出
    if(k == 8 && a[k] <= 8)
    {
      for(i = 1;i <= 8;i++)
      {
        printf("%d\t",a[i]);
      }
      ++j;
      printf("\n");
    }
    //如果还有皇后没有放好，开始移动下一个皇后
    else if(k < 8 && a[k] <= 8)
      {
          ++k;
      }
    //如果皇后位置不在1-8以内，将当前皇后位置移回0，然后改移上一个皇后。
    else
      {
        a[k] = 0;
        --k;

      }
  }
  printf("%d种方案\n",j);
}

void queen1(int k)
{
  int i;
  int j = 0;
  if(k > 8)
  {
    for(i = 1;i <= 8;i++)
    {
      printf("%d\t",a[i]);
    }
    ++j;
    printf("\n");
  }
  else
  {
    for(i = 1;i <= 8;i++)
    {
      a[k] = i;
      if(isvalid(k)) queen1(k+1);
    }
  }
  // printf("%d",j);
}
int main()
{
  int k = 1;
  queen1(k);
  queen();
  return 0;
  // printf("%d",j);
}
