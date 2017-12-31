#define MAX 3
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    if((fp = fopen("/Users/jiawei/c/ex/11_2/11_2/a1.txt","r")) == NULL)
    {
        printf("can not open the file!");
        exit(0);
    }
    int i = 0;
    int a[MAX][MAX];
    int b[MAX][MAX];
    for(i = 0;i < MAX;++i)
    {
        for(int j = 0;j < MAX;++j)
        {
            fscanf(fp,"%d ",&a[i][j]);
        }
        
    }
    if((fp = fopen("/Users/jiawei/c/ex/11_2/11_2/a2.txt","w")) == NULL)
    {
        printf("can not open the file!");
        exit(0);
    }
    for(i = 0;i < MAX;++i)
    {
        for(int j = 0;j < MAX;++j)
        {
            fprintf(fp,"%d ",a[j][i]);
        }
        fprintf(fp,"\n");
        
    }
}
