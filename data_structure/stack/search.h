#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max_length 100
// #include "stringreplace.h"
typedef char str[max_length];

//从pos开始在S里查找，找到和T一样的串，返回位置给K
int Index(str S,str T,int pos)
{
  int i,j;
  i = pos - 1;
  while(i < strlen(S))
  {
    j = 0;
     while(i < strlen(S) && j < strlen(T))
    {
      if (S[i] == T[j])
      {
        ++i;
        ++j;
      }
      else
      {
        i = i - j + 1;
        j = 0;
      }
    }
    if (j >= strlen(T))
    {
        // K = i - strlen(T) + 1;
        printf("The word is at %lu\n",i - strlen(T) + 1);
        // return 0;
    }
  }
  return 0;
}

int Index1(str S,str T,int pos)
{
  int next[100];
  int x = 1;
  next[1] = 0;
  int y = 0;
  while(x < strlen(T))
  {
    if(y == 0 || T[x] == T[y]) {++x; ++y; next[x] = y;}
    else y = next[y];
  }

  int i = pos;
  int j = 1;
  while(i < strlen(S))
  {
    while(i <= strlen(S) && j <= strlen(T))
    {
      if (j == 0 || S[i - 1] == T[j - 1]){
        ++i;
        ++j;
      }
      else j = next[j];
    }
    if (j > strlen(T))
    {
      printf("The word is at %lu\n",i - strlen(T));
    }
    j = 0;
  }
  return 0;
}

int Dist(str T, char ch)
{
  int len = strlen(T);
  int i = len - 1;
  if (ch == T[i])
    return len;
  i--;
  while (i >= 0)
  {
    if (ch == T[i])
      return len - 1 - i;
    else
      i--;
  }
  return len;
}

int BM(str S, str T,int pos)
{
  int n = strlen(S);
  int m = strlen(T);
  int i = pos + m;
  int j = m - 1;
  while (j >= 0 && i<n)
  {
    if (S[i] == T[j])
    {
    i--;
    j--;
  }
  else
  {
    i += Dist(T, S[i]);
    j = m - 1;
    }
    }
  if (j < 0)
  {
    // printf("%d\n",i+2);
    return i+2;
  }

    return -1;
  }
