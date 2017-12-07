#include "head.h"
#include <stdio.h>
int Insert_Sort(SqList &L,int length){
	int i;
	int j;
	for(i = 2;i <= length;++i){
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
	int length;
	Input(L,length);
	Insert_Sort(L,length);
	Output(L,length);
	return 0;
}
	

