#include "head.h"
#include <stdio.h>
int SelectSort(SqList &L)
{
    int i;
    for(i = 1;i <= MAXSIZE;++i)
    {
        int index = 0;
        int j;
        int min = L.r[i].key;
        for(j = i + 1;j <= MAXSIZE;++j)
        {
            if(L.r[j].key < min)
            {
                min = L.r[j].key;
                index = j;
            }
        }
        if(index != 0)
        {
            int t = L.r[index].key;
            L.r[index].key = L.r[i].key;
            L.r[i].key = t;
        }
    }
    return 0;
}

int main()
{
    SqList L;
    Input(L);
    time(&t1);
    SelectSort(L);
    time(&t2);
    Output(L);
    char string[] = "选择排序的时间:";
    Output_file(t1,t2,string);
    // printf("%ld %ld %ld", t1, t2, t2 - t1);
    return 0;
}
