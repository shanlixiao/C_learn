#include "head.h"
#include <stdio.h>
int Insert_Sort(SqList &L){
	int i;
	int j;
	for(i = 2;i <= MAXSIZE;++i){
		if(L.r[i].key < L.r[i-1].key){
			L.r[0].key = L.r[i].key;
			for(j = i - 1;j >= 1 && L.r[0].key < L.r[j].key;--j){
				L.r[j+1].key = L.r[j].key;
			}
			L.r[j+1].key = L.r[0].key;
		}
	}
	return 0;
}

int main()
{
	int i;
	SqList L;
	Input(L);
	time(&t1);
	Insert_Sort(L);
	time(&t2);
	Output(L);
	char string[] = "插入排序的时间:";
	Output_file(t1,t2,string);
	printf("%ld %ld %ld\n",t1,t2,t2-t1);
	return 0;
}
