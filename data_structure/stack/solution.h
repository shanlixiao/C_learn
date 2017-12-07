#include "stack.h"
typedef char str[100];
void solution(str s)
{
  SqStack S,M,N,P;
  Init(S);
  Init(M);
  Init(N);
  Init(P);
  int i;
  for(i = 0;i < strlen(s);i++)
  {
    switch(s[i])
    {
      case '+':
      //加法优先级最低
      {
        if(getTop(S) == '*' || getTop(S) == '/' || getTop(S) == '+' || getTop(S) == '-')
        {
          printf("%c",getTop(S));
          Push(M,getTop(S));
          Pop(S);
          Push(S,'+');
        }

        else
          Push(S,'+');
      }
      break;
      case '-':
      //减法和加法类似
      {
        if(getTop(S) == '*' || getTop(S) == '/' || getTop(S) == '+' || getTop(S) == '-')
        {
          printf("%c",getTop(S));
          Push(M,getTop(S));
          Pop(S);
          Push(S,'-');
        }
        else
          Push(S,'-');
      }
      break;
      case '*':
      {
        if(getTop(S) == '*' || getTop(S) == '/')
        {
          printf("%c",getTop(S));
          Push(M,getTop(S));
          Pop(S);
          Push(S,'*');
        }
        else
          {
            Push(S,'*');
          }
      }//case
      break;
      case '/':
        {
            if(getTop(S) == '*' || getTop(S) == '/')
             {
               printf("%c",getTop(S));
               Push(M,getTop(S));
               Pop(S);
               Push(S,'/');
             }
             else
               {
                 Push(S,'/');
               }
        }//case
      break;
      case '(':
        Push(S,'(');
      break;
      case ')':
      {
        while (getTop(S) != '(')
        {
          printf("%c",getTop(S));
          Push(M,getTop(S));
          Pop(S);
        }
        Pop(S);
      }
      break;
      default:
        {
          printf("%c",s[i]);
          Push(M,s[i]);
        }
    }//switch
  }//for
  while(S.base != S.top)
  {
  printf("%c",*(S.top - 1));
  Push(M,*(S.top - 1));
  Pop(S);
  }
  printf("\n");
  // printf("%c\n",*(M.top - 1));
  while(M.base != M.top)
  {
    Push(N,*(M.top-1));
    Pop(M);
  }//while

  int p = 0;
  while(N.base != N.top)
  {
    if(*(N.top - 1) != '+' && *(N.top - 1) != '-' && *(N.top - 1) != '*' && *(N.top - 1) != '/')
    {
      *(N.top - 1) = (int)*(N.top - 1) - 48;
      *P.top = *(N.top - 1);
      --N.top;
      ++P.top;
    }
    else
    {
      switch(*(N.top - 1))
      {

      case '+':
        {
          p = *(P.top - 2) + *(P.top - 1);
          Pop(P);
          Pop(P);
          Push(P,p);
        }
        break;
      case '-':
        {
          p = *(P.top - 2) - *(P.top - 1);
          Pop(P);
          Pop(P);
          Push(P,p);
        }
        break;
      case '*':
        {
          p = *(P.top - 2) * *(P.top - 1);
          Pop(P);
          Pop(P);
          Push(P,p);
        }
        break;
      case '/':
        {
          p = *(P.top - 2) / *(P.top - 1);
          Pop(P);
          Pop(P);
          Push(P,p);
        }
        break;
      }//switch
      --N.top;
    }//else

  }//while
  printf("表达式结果为：");
  printf("%d\n",*P.base);
  }
