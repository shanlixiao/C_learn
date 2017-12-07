#include <stdio.h>
//
int isvalid(int a[],int k)
{
  int i;
  for(i = 0;i < k;i++)
  {
    if(a[i] == a[k] && abs(a[i] - i) == abs(b[j] - j))
      return 0;
  }
  return 1;
}

void queen()
{
  int k,a[9],i;
  a[8] = {0};
  k = 1;
  while(k >= 1)
  {
    a[k] += 1;
    while(!isvalid(a[k],k) && k <= 8)
      a[k] += 1;
    if(k == 8)
    {
      for(i = 1;i <= 8;i++)
      {
        printf("%d\t",a[i]);
      }
    }
    else if(k < 8)
    {
      ++k;
    }
    else
    {
      --k;
      a[k] = 0;
    }
  }
}
int main()
{
  queen();
}
