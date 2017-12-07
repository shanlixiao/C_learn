//
//  main.c
//  7_2
//
//  Created by 佳炜 on 2017/11/24.
//  Copyright © 2017年 佳炜. All rights reserved.
//

#include <stdio.h>
void fun(int a[100],int p,int m)
{
    int b[100];
    int i;
    for(i = 0;i <= p;++i) b[i] = a[i];
    for(i = p + 1;i < m;++i) a[i - p - 1] = a[i];
    for(i = 0;i <= p;++i) a[m - p + i - 1] = b[i];
    for(i = 0;i < m;++i) printf("%d ",a[i]);
}

int main()
{
    int m;
    printf("输入几位：");
    scanf("%d",&m);
    int i;
    int a[100];
    for(i = 0;i < m;++i)
        scanf("%d",&a[i]);
    int p;
    printf("移动几位:");
    scanf("%d",&p);
    fun(a,p,m);
    return 0;
}
