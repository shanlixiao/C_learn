#define N 10
#include <stdio.h>
void fun(int *a,int n,int *odd,int *even){
    int i;
    *odd = 0;
    *even = 0;
    for(i = 0;i < n;++i){
        if(*(a + i) % 2 == 1) *odd += *(a + i);
        else *even += *(a + i);
    }
}
int main(int argc, const char * argv[]) {
    int a[N];
    int n,i = 0,j = 0;
    int *odd = &i,*even = &j;
    printf("Please input the number:");
    scanf("%d",&n);
    for(i = 0;i < n;++i){
        scanf("%d",(a + i));
    }
    fun(a,n,odd,even);
    printf("%d,%d\n",*odd,*even);
    return 0;
}
