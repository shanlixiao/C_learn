#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define max_length 100
typedef char str[max_length];

//串赋值
// void StrAssign(str &S,str T)
// {
//   strcpy(S,T);
// }

//将S和T连接，赋给S
int StrConcat(str &S,str T,str V)
{
  int i,j,k;
  i = strlen(T);
  j = strlen(V);
  for(k = 0;k <= i - 1;k++)
  {
    S[k] = T[k];
  }
  for(k = i;k <= i + j - 1;k++)
  {
    S[k] = V[k - i];
  }
  return 0;
}

//从pos开始在S里查找，找到和T一样的串，返回位置给K
int Index(str S,str T,int pos,int &K)
{
  int i,j;
  i = pos - 1;
  // while(i < strlen(S))
  // {
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
        K = i - strlen(T) + 1;
        // printf("The world is at %lu\n",i - strlen(T) + 1);
        return 0;
    }
    else
    {
      K = 0;
      return 0;
    }
  // }
  // return 0;
}

int Indexloop(str S,str T,int pos)
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
        i = i - j + 2;
        j = 0;
      }
    }
    if (j >= strlen(T))
    {
        printf("The world is at %lu\n",i - strlen(T) + 1);
    }
  }
  return 0;
}

//S里从i开始j个字符赋给T
int Substring(str S,str T,int i,int j)
{
  int k;
  for(k = i - 1;k <= i + j - 2;k++)
  {
    T[k - i + 1] = S[k];
  }
  return 0;
}

int StrReplace(str &S,str T,str V)
{
  int K = 0;
  Index(S,T,1,K);
  // printf("%d",K);
  if(K)
  {
    str temp,A,B,C,D;
    int i,j;
    i = strlen(T);
    j = strlen(S);

    while(K)
    {
      // printf("%d",K);
      Substring(S,A,1,K - 1);
      StrConcat(D,A,V);
      StrConcat(temp,temp,D);
      j -= (K - 1) - i;
      Substring(S,B,K + i,j);
      strcpy(S,B);
      Index(S,T,1,K);
    }
    StrConcat(C,temp,S);
    strcpy(S,C);
  }//if
  return 0;
}
