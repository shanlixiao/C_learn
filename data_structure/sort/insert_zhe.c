#include "head.h"
#include <stdio.h>
void Insert_zhe(SqList &L,int &length){
	int i;
	int j;
	for(i = 2;i <= length;++i){
		if(L.r[i].key < L.r[i-1].key){
			L.r[0].key = L.r[i].key;
			int low,high,mid;
			low = 1;
			high = i - 1;
			while(low <= high){
				mid = (low + high)/2;
				if(L.r[mid].key < L.r[i].key)
					low = mid + 1;
				else high = mid - 1;
			}
			for(j = i - 1;j >= high+1;--j){
				L.r[j+1].key = L.r[j].key;
			}
			L.r[j+1].key = L.r[0].key;
		}
	}
}
int main()
{
	SqList L;
	int length;
	Input(L,length);
	Insert_zhe(L,length);
	Output(L,length);
	return 0;
}
