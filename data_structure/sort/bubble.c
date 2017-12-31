#include "head.h"
#include <stdio.h>
#include <stdlib.h>

void bubble(SqList &L) {
  int i, j;
  for (i = MAXSIZE; i > 1; --i) {
    for (j = 2; j <= i; ++j) {
      if (L.r[j - 1].key > L.r[j].key)
        swap(L.r[j - 1].key, L.r[j].key);
    } // if
  }   // for
} // for

int main() {
  SqList L;
  Input(L);
  time(&t1);
  bubble(L);
  time(&t2);
  Output(L);
  char string[] = "冒泡排序的时间:";
  Output_file(t1,t2,string);
  // printf("%ld %ld %ld", t1, t2, t2 - t1);
  return 0;
}
