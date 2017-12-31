#include <stdio.h>
#include <string.h>
#define N 5

void sort(int *array){
	int len = N;
	int i,j,t;
	for(i = len;i > 1;--i)
		for(j = 1;j < len;++j){
			if(array[j] < array[j-1]){
				t = array[j-1];
				array[j-1] = array[j];
				array[j] = t;
			}
		}
}
int main()
{
	int array[N];
	int i;
	for(i = 0;i < N;++i){
		scanf("%d",&array[i]);
	}
	sort(array);

	for(i = 0;i < N;++i){
		printf("%d\t",array[i]);
	}
	printf("\n");
	int b[N];
	int k = 0;
	int j;
	for(i = 0,j = N - 1;i <= j;++i,--j){
		b[k] = array[i];
		b[k+1] = array[j];
		k = k + 2;
	}
	for(i = 0;i < N;++i){
		printf("%d\t",b[i]);
	}
	printf("\n");
	return 0;
}
	
