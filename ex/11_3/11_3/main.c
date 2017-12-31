#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp;
    if((fp = fopen("/Users/jiawei/c/ex/11_3/11_3/data.txt","w")) == NULL)
    {
        printf("can not open the file!");
        exit(0);
    }
    char string[20];
    char string2[20];
    gets(string);
    int i = 0;
    while(string[i] != '\0')
    {
        if(string[i] >= 'a' && string[i] <= 'z')
            string[i] -= 32;
        ++i;
    }
    fputs(string,fp);
    fclose(fp);
    if((fp = fopen("/Users/jiawei/c/ex/11_3/11_3/data.txt","r")) == NULL)
    {
        printf("can not open the file!");
        exit(0);
    }
    
    fscanf(fp,"%s",string2);
    puts(string2);
}
