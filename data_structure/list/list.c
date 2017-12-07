#include <stdio.h>
#include <string.h>
#define OK 1
#define ERROR 0
#define Max_Length 100
#define ElemType int
// Status是函数类型
typedef int Status;
typedef struct
{
  int data[Max_Length];
  int length;
}SqList;
void List_Customize(SqList &L)
{
  printf("请输入表长:\n");
  int i;
  scanf("%d",&i);
  L.length = i;
  printf("请输入表元素:");
  int j;
  for (j = 0;j < i;j++)
  {
    scanf("%d",&(L.data[j]));
  }
}

Status List_Init(SqList &L)
{
  L.length = 0;
  return OK;
}
int List_Insert(SqList &L,int i,int e)
{
  int *p;
  int *q;
  //插入位置的前一位置
  q = &(L.data[i - 1]);
  //插入位置的后面的元素后移一位
  for(p = &L.data[L.length - 1];p >= q;--p)
  {
    *(p + 1) = *p;
  }
  *q = e;
  ++L.length;
  return 0;
}
//按元素删除
int List_Delete_Elem(SqList &L,ElemType e)
{
  int j;
  //找到第一个所给元素
  for (j = 0;j <= L.length - 1;j++)
  {
    if(L.data[j] == e) break;
  }
  if (j >= L.length)
  {
    return 0;
  }
  int *p = &(L.data[j]);
  int *q = &L.data[0] + L.length -1;
  //删除元素的后面元素前移
  for (++p;p <= q;++p)
    {
      *(p - 1) = *p;
    }
  --L.length;
  return 1;
}

// 按照位置，删除表中指定位置元素
Status List_Delete_Pos(SqList &L, int i)
{
  if (i < 1 || i > L.length)
  {
    return 0;
  }
  int *p = &(L.data[i-1]);
  int *q = &L.data[0] + L.length -1;
  for (++p; p <= q; ++p)
    {
      *(p - 1) = *p;
    }
  --L.length;
  return 1;
}
//按元素替换
Status List_Replace_Elem(SqList &L,int m,int n)
{
  int i;
  //查找元素
  for (i = 0;i <= L.length - 1;i++)
    if(L.data[i] == m)
      break;
  if (i >= L.length)
  {
    printf("没有该元素\n");
    return ERROR;
  }
  int *p;
  p = &(L.data[i]);
  *p = n;
  return OK;
}
//按位置替换
Status List_Replace_Pos(SqList &L,int i,int m)
{
  int *p;
  if (i < 0 || i > L.length)
  {
    printf("error，位置大于表长\n");
    return ERROR;
  }
  p = &(L.data[i - 1]);
  *p = m;
  return OK;
}
//按位置查找
Status List_Find_Pos(SqList L,int i)
{
  if (i < 0 || i > L.length)
  {
    printf("error，位置大于表长\n");
    return ERROR;
  }
  printf("该位置元素为");
  printf("%d\n",L.data[i-1]);
  return OK;
}
//按元素查找
Status List_Find_Elem(SqList L,int m)
{
  int i;
  for (i = 0;i <= L.length - 1;i++)
  {
      if(L.data[i] == m)
    {
      printf("该元素的位置为");
      printf("%d\n",i + 1);
      break;
    }
  }
    if (i >= L.length)
    {
      printf("没有该元素\n");
      return ERROR;
    }
  return OK;
}
void List_Show_All (SqList L)
{
  for (int i = 1;i<= L.length; i++)
  {
    printf("%d\t",L.data[i-1]);
  }
  printf("\n");
}

Status List_Sort(SqList &L)
{
  int i,j,key;
  for (i = 1;i <= L.length - 1;i++)
  {
    j = i - 1;
    key = L.data[i];
    while(j >= 0 && L.data[j] > key)
    {
      L.data[j + 1] = L.data[j];
      L.data[j] = key;
      --j;
    }
  }
  return OK;
}

void List_Show_Length(SqList L)
{
  printf("%d\n",L.length);
}

void List_Clear(SqList &L)
{
  L.length = 0;
}
void show()
{
  printf("**********顺序表菜单**********\n");
  printf("0.重新自定义表\t1.初始化表\n2.插入元素\t");
  printf("3.按元素删除\n4.按位置删除\t");
  printf("5.按元素查找\n6.按位置查找\t");
  printf("7.按元素替换\n8.按位置替换\t");
  printf("9.查看所有元素\n10.查看表长\t");
  printf("11.排序表\n12.清空表\t13.结束程序\n");
  printf("******************************\n");
}


int main(int argc, char const *argv[])
{
  char a[20];
  printf("线性表操作即将开始，yes/no?\n");
  scanf("%s",a);
  if (!strcmp(a,"yes"))
  {
    show();
    while(1)
    {
      int x;
      SqList L;
      printf("Hey,请选择菜单编号：");
      scanf("%d",&x);
      if (x == 13)
        break;
      switch(x)
      {
        case 0:
        {
          printf("现在开始重新自定义表\n");
          List_Customize(L);
        }
        break;
        case 1:
        {
          printf("初始化表\n");
          List_Init(L);
        }
        break;
        case 2:
        {
          printf("现在开始插入元素\n");
          int i,e;
          printf("请输入你想插入的元素位置：");
          scanf("%d",&i);
          if (i > L.length + 1)
            {
              printf("error,元素位置大于表长\n");
              break;
            }
          printf("请输入你想在该位置插入的元素：");
          scanf("%d",&e);
          List_Insert(L,i,e);
        }
        break;
        case 3:
        {
          printf("现在开始按元素删除\n");
          int j;
          printf("请输入你想删除的元素：");
          scanf("%d",&j);
          List_Delete_Elem(L,j);
        }
        break;
        case 4:
        {
          int j;
          printf("现在开始按元素位置删除\n");
          printf("请输入你想删除的元素位置：");
          scanf("%d",&j);
          List_Delete_Pos(L,j);
        }
        break;
        case 5:
        {
          int j;
          printf("请输入你想查找的元素：");
          scanf("%d",&j);
          List_Find_Elem(L,j);
        }
        break;
        case 6:
        {
          int j;
          printf("请输入你想查找的元素位置：");
          scanf("%d",&j);
          List_Find_Pos(L,j);
        }
        break;
        case 7:
        {
          int i,j;
          printf("现在开始按元素替换\n");
          printf("请输入你想替换的元素：");
          scanf("%d",&j);
          printf("你想把该位置元素替换为：");
          scanf("%d",&i);
          List_Replace_Elem(L,j,i);
        }
        break;
        case 8:
        {
          int i,j;
          printf("现在开始按元素位置删除\n");
          printf("请输入你想替换的元素位置：");
          scanf("%d",&j);
          printf("你想把该元素替换为：");
          scanf("%d",&i);
          List_Replace_Pos(L,j,i);
        }
        break;
        case 9:
        {
          printf("表的所有元素为:\n");
          List_Show_All(L);
        }
        break;
        case 10:
        {
          printf("表长为:\n");
          List_Show_Length(L);
        }
        break;
        case 11:
        {
          List_Sort(L);
          printf("排序后为：\n");
          List_Show_All(L);
        }
        break;
        case 12:
        {
          printf("清空表\n");
          List_Clear(L);
        }
        break;
      }
    }
  }
  else
    return ERROR;
}
