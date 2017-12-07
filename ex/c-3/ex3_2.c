#include <stdio.h>
#include <math.h>
int main()
{
  int a,b,c;
  double p=0,S=0;
  scanf("%d%d%d",&a,&b,&c);
  if ( (a + b > c) && (a + c > b) && (b + c > a))
  {
    p = (a + b + c) / 2.0;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("%f",S);
  }
  else printf("No");
}
