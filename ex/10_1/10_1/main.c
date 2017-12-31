//
//  main.c
//  10_1
//
//  Created by 佳炜 on 2017/12/8.
//  Copyright © 2017年 佳炜. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main(int argc, const char * argv[]) {
    
    int n;
    printf("input the total students number:");
    scanf("%d",&n);
    typedef struct {
        char name[20];
        int number;
        char sex;
        char college[20];
    }student[n],temp;
    printf("input the info:\n");
    int i;
    student student1;
    for(i = 0;i < n;++i){
        printf("the %d\n",i+1);
        scanf("%s %d %c %s",student1[i].name,&student1[i].number,&student1[i].sex,student1[i].college);
        printf("\n");
    }
    int j;
    temp temp1;
    for(i = n-1;i >= 1;--i){
        for(j = 1;j <= i;++j){
            if(student1[j-1].number > student1[j].number){
                temp1 = student1[j-1];
                student1[j-1] = student1[j];
                student1[j] = temp1;
            }// if
        }// for
    }
    for(i = 0;i < n;++i){
        printf("%s\t%d\t%c\t%s\n",student1[i].name,student1[i].number,student1[i].sex,student1[i].college);
    }
    char college1[20];
    int s = 0;
    scanf("%s",college1);
    for(i = 0;i < n;++i){
        if(!strcmp(college1,student1[i].college)){
            s++;
        }
    }
    printf("%d\n",s);
    
    return 0;
}
