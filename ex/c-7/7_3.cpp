//
//  main.c
//  7_3
//
//  Created by 佳炜 on 2017/11/24.
//  Copyright © 2017年 佳炜. All rights reserved.
//

#include <stdio.h>
int fun(int a[100],int &length){
    int i = 0;  
    int j = 0;
    int n;
    for(;i < length;i++)
        for(j = i + 1;j < length;++j)
        {
            if(a[j] == a[i])
            {
                for(n = j + 1;n < length;n++)
                    a[n - 1] = a[n];
                --length;
                --i;
            }
        }
    return length;
}

int main()
{
    int length;
    int i;
    scanf("%d",&length);
    int a[100];
    for(i = 0;i < length;++i)
        scanf("%d",&a[i]);
    printf("删除后数组个数:%d\n",fun(a,length));
    return 0;
}
