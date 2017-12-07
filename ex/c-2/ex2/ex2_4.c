#include <stdio.h>
int main()
{
  float n,x;
  scanf("%f",&n);
  if((int)(n * 1000) % 10 >= 5)
    x = (float)((int)(n * 100 + 1))/100;
  else
    x = (float)((int)(n * 100))/100;
  //x = (float)((int)(n*100 + 0.5))/100;
  printf("x=%f",x);
}
