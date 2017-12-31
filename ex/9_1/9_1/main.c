#include <stdio.h>
#include <string.h>
#define M 5
#define N 10
void sort(char *string[]){
    int i,j;
    char *t;
    for(i = 1;i < M;++i){
        for(j = 0;j < M - i;++j){
            if(strcmp(string[j],string[j+1]) > 0){
                t = string[j];
                string[j] = string[j+1];
                string[j+1] = t;
            }
        }
    }
}
int main()
{
    char str[M][N];
    static char *string[M];
    int i;
    
    for(i = 0;i < M;++i){
        printf("the %d:",i);
        scanf("%s",*(str + i));
    }
    for(i = 0;i < M;++i){
        string[i] = *(str + i);
    }
    sort(string);
    for(i = 0;i < M;++i)
        printf("%s\n",string[i]);
    
}
