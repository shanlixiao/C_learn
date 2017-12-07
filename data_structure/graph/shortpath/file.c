#include <stdio.h>
#include <stdlib.h>
#include "head.h"
int main()
{
//   FILE *fp;
//   char ch,ch1;
//   //write character to a file
//   if((fp = fopen("file_data.txt","w")) == NULL)
//   {
//     printf("can not open the file\n");
//     exit(0);
//   }
//   ch = getchar();
//   while(ch != '#')
//   {
//     fputc(ch,fp);
//     ch = getchar();
//   }
//   fclose(fp);
//   //read character to a file
//   if((fp = fopen("file_data.txt","r")) == NULL)
//   {
//     printf("can not open the file\n");
//     exit(0);
//   }
//   ch1 = fgetc(fp);
//   while(ch1 != EOF)
//   {
//     putchar(ch1);
//     ch1 = fgetc(fp);
//   }
//   fclose(fp);
//
//   if((fp = fopen("file_data.txt","w")) == NULL)
//   {
//     printf("can not open the file\n");
//     exit(0);
//   }
//
  MGraph G;
  FILE *fp;
  // int a[20][20];
  // int vexnum,arcnum;
  if((fp = fopen("data.txt","r")) == NULL)
  {
    printf("can not open the file!\n");
    exit(0);
  }
  printf("Please input the vexnum and arcnum:\n");
  printf("vexnum:");
  scanf("%d",&G.vexnum);
  printf("arcnum:");
  scanf("%d",&G.arcnum);
  int i,j;
  int k = 1;
  for(i = 0;i < G.vexnum;++i)
    for(j = 0;j < G.vexnum;++j)
    {
      fscanf(fp,"%d ",&G.arcs[i][j].adj);
      printf("%d\n",k);
      ++k;
    }
    fclose(fp);
  // printf("aaaa");
}
