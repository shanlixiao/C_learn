#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int stu_num;
    char name[20];
    int course1;
    int course2;
    int course3;
    int ave;
}student[5];

int main()
{
    int i;
    student stu;
    for(i = 0;i < 3;i++)
    {
        printf("the %d\n",i+1);
        scanf("%d %s %d %d %d",&stu[i].stu_num,stu[i].name,&stu[i].course1,&stu[i].course2,&stu[i].course3);
        
    }
    for(i = 0;i < 5;++i)
    {
        stu[i].ave = (stu[i].course1 + stu[i].course2 + stu[i].course3) / 3;
    }
    FILE *fp;
    if((fp = fopen("/Users/jiawei/c/ex/11_1/11_1/data.txt","w")) == NULL)
    {
        printf("can not open the file");
        exit(0);
    }
    for(i = 0;i < 5;i++)
    {
        fprintf(fp,"%d %s %d %d %d\n",stu[i].stu_num,stu[i].name,stu[i].course1,stu[i].course2,stu[i].course3);
    }
    return 0;
    
}
