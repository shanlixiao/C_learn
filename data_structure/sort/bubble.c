#include "head.h"

void swap(int &a,int &b){
  int t;
  t = a;
  a = b;
  b = t;
}

void bubble(SqList &L,int length){
  int i,j;
  for(i = length;i > 1;--i){
    for(j = 2;j <= i;++j){
      if(L.r[j-1].key > L.r[j].key)
        swap(L.r[j-1].key,L.r[j].key);
    }// if
  }// for
}// for

int main(){
  SqList L;
  int length;
  Input(L,length);
  bubble(L,length);
  Output(L,length);
  return 0;
}
