#include <stdio.h>
int main()
{
  float a;
  scanf("%f",&a);
  int b;
  b = a/10;
  switch(b)
  {
    case 9:printf("A");break;
    case 10:printf("A");break;
    case 8:printf("B");break;
    case 7:printf("C");break;
    case 6:printf("D");break;
    default:printf("E");
  }
}
