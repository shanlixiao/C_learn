#include "head.h"
#include <stdio.h>

int partition(SqList &L,int left,int right)
{
    int storeIndex = left;
    int k;
    for(k = left;k <= right - 1;++k)
    {
        if(L.r[k].key < L.r[right].key)
        {
            swap(L.r[k].key,L.r[storeIndex].key);
            ++storeIndex;
        }
    }
    swap(L.r[right].key,L.r[storeIndex].key);
    return storeIndex;
}

void sort(SqList &L,int left,int right)
{
    if(left > right){
        return;
    }
    int storeIndex = partition(L,left,right);
    sort(L,left,storeIndex - 1);
    sort(L,storeIndex + 1,right);
}

int main()
{
    SqList L;
    Input(L);
    time(&t1);
    sort(L,1,MAXSIZE);
    time(&t2);
    Output(L);
    char string[] = "快速排序的时间:";
    Output_file(t1,t2,string);
    printf("%lds\n",t2-t1);
    return 0;
}
