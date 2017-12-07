#include <stdio.h>
#define MAXSIZE 20
typedef int KeyType;
typedef struct{
	KeyType key;
}RecordType;
typedef struct{
	RecordType r[MAXSIZE];
	int length;
}SqList;

void Input(SqList &L,int &length){
	int i;
	printf("Please input the total number that you want to input:");
	scanf("%d",&length);
	for(i = 1;i <= length;++i){
		scanf("%d",&L.r[i].key);
	}
}
void Output(SqList L,int length){
	int i;
	for(i = 1;i <= length;++i){
		printf("%d\t",L.r[i].key);
	}
	printf("\n");
}
