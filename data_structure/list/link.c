#include "link.h"
int main()
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
      Linklist L;
      printf("Hey,请选择菜单编号：");
      scanf("%d",&x);
      if (x == 13)
        break;
      switch(x)
      {
        case 0:
        {
					int n;
          printf("现在开始重新自定义表\n");
          List_Create_order(L,n);
        }
        break;
        case 1:
        {
          printf("初始化表\n");

        }
        break;
        case 2:
        {
          printf("现在开始插入元素\n");
          int i,e;
          printf("请输入你想插入的元素位置：");
          scanf("%d",&i);
          // if (i > List_Show_Length(L))
          //   {
          //     printf("error,元素位置大于表长\n");
          //     break;
          //   }
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

          printf("排序后为：\n");
          List_Show_All(L);
        }
        break;
        case 12:
        {
          printf("清空表\n");

        }
        break;
      }
    }
  }
  else
    return ERROR;
}
