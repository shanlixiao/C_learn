#include <stdio.h>
void fun(int *odd,int *even){
  *odd = 0;
  *even = 0;
}

int main(){
  int odd = 2;
  int even = 4;
  fun(&odd,&even);
  printf("%d %d",odd,even);
}
