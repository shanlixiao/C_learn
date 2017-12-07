#include "head.h"
void shell_sort(SqList &L,int dk,int length){
  int i,j;
  for(i = dk + 1;i <= length;++i){
    if(L.r[i].key < L.r[i-dk].key){
      L.r[0].key = L.r[i].key;
      for(j = i - dk;L.r[0].key < L.r[j].key && j >= 1;j = j - dk){
        L.r[j+dk].key = L.r[j].key;
      }
      L.r[j+dk].key = L.r[0].key;
    }// if
  }// for
}

void shell(SqList L){
  int i;
  int dk,length = 0;
  Input(L,length);
  int df[] = {3,1};
  for(i = 0;i < 2;++i){
    dk = df[i];
    shell_sort(L,dk,length);
  }
  Output(L,length);
}
int main()
{
  SqList L;
  shell(L);
}
