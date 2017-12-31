#include <stdio.h>
#include <stdlib.h>
#include <time.h>
time_t t1,t2;
#define MAXSIZE 100000
typedef int KeyType;
typedef struct{
	KeyType key;
}RecordType;
typedef struct{
	RecordType r[MAXSIZE];
	int length;
}SqList;

void swap(int &a,int &b)
{
	int t = a;
	a = b;
	b = t;
}
void Input(SqList &L)
{
	FILE *fp;
	if((fp = fopen("data.txt","r")) == NULL)
	{
		printf("can not open the file!");
		exit(0);
	}
	int i;
	for(i = 1;i <= MAXSIZE;++i)
	{
		fscanf(fp,"%d",&L.r[i].key);
	}
	fclose(fp);

}
// void Input(SqList &L,int &length){
// 	int i;
// 	printf("Please input the total number that you want to input:");
// 	scanf("%d",&length);
// 	for(i = 1;i <= length;++i){
// 		scanf("%d",&L.r[i].key);
// 	}
// }
// void Output(SqList L,int length){
// 	int i;
// 	for(i = 1;i <= length;++i){
// 		printf("%d\t",L.r[i].key);
// 	}
// 	printf("\n");
// }
void Output(SqList L)
{
	int i;
	for(i = 1;i <= MAXSIZE;++i)
	{
		printf("%d\n",L.r[i].key);
	}
}

void Output_file(int t1,int t2,char *string)
{
	FILE *fp;
	if((fp = fopen("output.txt","a+")) == NULL)
	{
		printf("can not open the file!");
		exit(0);
	}
	fseek(fp,0,SEEK_END);
	fprintf(fp,"%s%ds\n",string,t2 - t1);
	fclose(fp);
}
