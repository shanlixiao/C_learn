//
//  cmp.c
//  clearn
//
//  Created by 佳炜 on 2017/11/23.
//  Copyright © 2017年 佳炜. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int string_cmp(char s1[100],char s2[100]){
    int i = 0,s;
    while(s1[i] != '\0' && s2[i] != '\0'){
        if(s1[i] == s2[i]){
            ++i;
        }
        else {
            s = s1[i] - s2[i];
            return s;
        }
    }
    if(i == strlen(s1) && i == strlen(s2))
        return 0;
    else if(i == strlen(s1) && i < strlen(s2))
        return s2[i] - '\0';
    else
        return s1[i] - '\0';
}

int main(){
    char s1[100];
    char s2[100];
    gets(s1);
    gets(s2);
    printf("%d\n",string_cmp(s1,s2));
    return 0;
}
