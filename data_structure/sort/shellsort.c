#include "head.h"
void shell_sort(SqList &L,int dk){
  int i,j;
  for(i = dk + 1;i <= MAXSIZE;++i){
    if(L.r[i].key < L.r[i-dk].key){
      L.r[0].key = L.r[i].key;
      for(j = i - dk;L.r[0].key < L.r[j].key && j >= 1;j = j - dk){
        L.r[j+dk].key = L.r[j].key;
      }
      L.r[j+dk].key = L.r[0].key;
    }// if
  }// for
}

void shell(SqList &L){
  int i;
  int dk;
  Input(L);
  int df[] = {15,12,9,6,3,1};
  for(i = 0;i < 6;++i){
    dk = df[i];
    shell_sort(L,dk);
  }
}
int main()
{
  SqList L;
  time(&t1);
  shell(L);
  time(&t2);
  Output(L);
  char string[] = "希尔排序的时间:";
  Output_file(t1,t2,string);
  return 0;
}
