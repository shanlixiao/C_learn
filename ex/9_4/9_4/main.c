//
//  main.c
//  9_4
//
//  Created by 佳炜 on 2017/12/1.
//  Copyright © 2017年 佳炜. All rights reserved.
//
#define N 100
#include <stdio.h>
void fun(char *a,int k,int n){
    int i = 0;
    int len = 0;
    while(a[i++] != '\0') ++len;
    for(i = k + n;i < len;++i){
        *(a + i - n) = *(a + i);
    }
    *(a + len - n) = '\0';
}
int main(int argc, const char * argv[]) {
    char a[N];
    gets(a);
    int k,n;
    printf("input the k and n:");
    scanf("%d%d",&k,&n);
    fun(a,k,n);
    puts(a);
    return 0;
}
