#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("input the n:");
    scanf("%d",&n);
    typedef struct student {
        int num;
        char name[20];
        int grade;
    }student[n];
    int i;
    student student1,student2;
    for(i = 0;i < n;++i)
    {
        printf("the %d:",i+1);
        scanf("%d%s%d",&student1[i].num,student1[i].name,&student1[i].grade);
    }
    FILE *fp;
    if((fp = fopen("/Users/jiawei/c/ex/11_4/11_4/student.dat","wb+")) == NULL)
    {
        printf("can not open the file!");
        exit(0);
    }
    for(i = 0;i < n;++i)
    {
        fwrite(&student1[i],sizeof(student),1,fp);
    }
    fclose(fp);
    if((fp = fopen("/Users/jiawei/c/ex/11_4/11_4/student.dat","rb+")) == NULL)
    {
        printf("can not open the file!");
        exit(0);
    }
    for(i = 0;i < n;++i)
    {
        fread(&student2[i],sizeof(student),1,fp);
    }
    fclose(fp);
    int max = student2[0].grade,min = student2[0].grade;
    for(i = 0;i < n;++i)
    {
        if(student2[i].grade > max)
            max = student2[i].grade;
        if(student2[i].grade < min)
            min = student2[i].grade;
    }
    printf("max:%d,min:%d\n",max,min);
    if((fp = fopen("/Users/jiawei/c/ex/11_4/11_4/score.txt","w+")) == NULL)
    {
        printf("can not open the file!");
        exit(0);
    }
    
    int j;
    student t;
    for(i = n;i > 1;--i)
    {
        for(j = 1;j < i;++j)
        {
            if(student2[j-1].grade > student2[j].grade)
            {
                t[0] = student2[j];
                student2[j] = student2[j-1];
                student2[j-1] = t[0];
            }
        }
    }
    for(i = 0;i < n;++i)
    {
        fprintf(fp,"%d\t%s\t%d\n",student2[i].num,student2[i].name,student2[i].grade);
    }

    
    fclose(fp);
    return 0;
}

