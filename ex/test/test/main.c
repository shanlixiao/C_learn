#include <stdio.h>
#include <string.h>
#define M 5
#define N 10
void sort(char (*p)[N]){
    int i,j;
    char t[N];
    for(i = 1;i < M;++i){
        for(j = 0;j < M - i;++j){
            if(strcmp(p[j],p[j+1]) > 0){
                strcpy(t,p[j]);
                strcpy(p[j],p[j+1]);
                strcpy(p[j+1],t);
            }
        }
    }
}
int main()
{
    char str[M][N];
    char (*p)[N];
    int i;
    
    for(i = 0;i < M;++i){
        printf("the %d:",i);
        scanf("%s",*(str + i));
    }
    p = str;
    // for(i = 0;i < M;++i){
    //     string[i] = *(str + i);
    // }
    sort(p);
    for(i = 0;i < M;++i)
        printf("%s\n",p[i]);
    
}
