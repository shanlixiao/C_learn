//
//  main.c
//  7_1
//
//  Created by 佳炜 on 2017/11/24.
//  Copyright © 2017年 佳炜. All rights reserved.
//
#include <stdio.h>
void fun(char a[100][100],int m,int n){
    char b[100];
    int i,j,y = 0;
    for(j = 0;j < n;j++)
        for(i = 0;i < m;++i)
            b[y++] = a[i][j];
    b[y] = '\0';
    puts(b);
}

int main()
{
    int m,n;
    printf("Please input the row and col:");
    scanf("%d%d",&m,&n);
    char a[100][100];
    int i,j;
    for(i = 0;i < m;++i)
        for(j = 0;j < n;++j)
            scanf(" %c",&a[i][j]);
    fun(a,m,n);
    return 0;
}
