#include <stdlib.h>
#include <stdio.h>
int main()
{
    FILE *fp;
    if((fp = fopen("Users/jiawei/c/ex/11_2/11_2/a1.txt","r")) == NULL)
    {
        printf("can not open the file!");
        exit(0);
    }
    int i = 0;
    int a[3][3];
    int b[3][3];
    for(i = 0;i < 3;++i)
    {
        for(int j = 0;j < 3;++j)
        {
            fscanf(fp,"%d",&a[i][j]);
        }
        
    }
    if((fp = fopen("Users/jiawei/c/ex/11_2/11_2/a2.txt","w")) == NULL)
    {
        printf("can not open the file!");
        exit(0);
    }
}
