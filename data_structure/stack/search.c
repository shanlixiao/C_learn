#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max_length 100
#include "search.h"
int main()
{
  FILE *fp;
  int i;
  str s[1000];
  str S;
  //Read the file
  fp = fopen("test1.txt","r");
  if (fp == NULL)
  {
    printf("can not open the file\n");
    exit(0);
  }
  fgets(*s,300,fp);
  puts(*s);
  fclose(fp);

  printf("Please input the word:\n");
  gets(S);
  printf("BF algorithm\n");
  Index(*s,S,1);
  printf("KMP algorithm\n");
  Index1(*s,S,1);
  int k = 1;
  printf("BM algorithm\n");
  while(k <= strlen(*s))
  {
    printf("The word is at %d\n",BM(*s,S,k));
    k = k + BM(*s,S,k) +strlen(S);

  }

}
