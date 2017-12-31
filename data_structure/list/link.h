#include <stdio.h>
#include <string.h>
#include <cstdlib>
#define ERROR -1;
#define OK 1;
typedef struct node
{
	int data;
	struct node *next;
}Lnode,*Linklist;

int List_Insert(Linklist &L,int i,int e)
{
	Linklist p,s;
	p = L;
	int j = 0;
	while(p->next && j < i - 1)
	{
		p = p ->next;
		++j;
	}
	if(!(p->next) || j > i - 1) return ERROR;
	s = (Linklist)malloc(sizeof(Lnode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1;
}

int List_Delete_Pos(Linklist &L,int i)
{
	Linklist p,q;
	p = L;
	int j,e ;
	j = 0;
	while(p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if(!(p->next) || j > i - 1) return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return 1;
}

int List_Delete_Elem(Linklist &L,int m)
{
	Linklist p,q;
	p = L;
	int j,e ;
	j = 0;
	while(p->next && p->next->data != m)
	{
		p = p->next;
	}
	if(!(p->next)) return ERROR;
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return 1;
}

int List_Replace_Pos(Linklist &L,int i,int m)
{
	Linklist p;
	p = L;
	int j;
	j = 1;
	while(p->next && j < i)
	{
		p = p->next;
		j++;
	}
	if(!(p->next)) return ERROR;
	p->data = m;
	return 1;
}


int List_Replace_Elem(Linklist &L,int e,int m)
{
	Linklist p;
	p = L;
	int j = 0;
	while(p->next && p->data != e)
	{
		p = p->next;
		j++;
	}
	if(!(p->next)) return ERROR;
	p->data = m;
	return OK;
}


int List_Find_Pos(Linklist &L,int i)
{
	Linklist p;
	p = L;
	int j = 0;
	int k;
	while(p->next && j < i)
	{
		p = p->next;
		j++;
	}
	if(!(p->next) || j > i - 1) return ERROR;
	k = p->data;
	return k;
}

int List_Find_Elem(Linklist &L,int e)
{
	Linklist p;
	p = L;
	int j = 0;
	while(p->next && p->data != e)
	{
		p = p->next;
		j++;
	}
	if(!(p->next)) return ERROR;
	printf("%d\n",j );
	return j;
}
void List_Show_All(Linklist &L)
{
	Linklist p;
	p = L;
	while(p->next)
	{
		p = p->next;
		printf("%d\t",p->data);
	}
	printf("\n");
}

int List_Show_Length(Linklist &L)
{
	Linklist p;
	p = L;
	int i = 0;
	while(p->next)
	{
		p = p->next;
		i++;
	}
	printf("%d\n",i);
	return i;
}

void List_Create_order(Linklist &L,int n)
{
	int i;
	printf("输入链表长:\n");
	scanf("%d",&n);
	Linklist p,t;
	L = (Linklist)malloc(sizeof(Lnode));
	L->next = NULL;
	t = L;
	printf("输入链表内容·:\n");
	for(i = n;i >0;i--)
	{
		p = (Linklist)malloc(sizeof(Lnode));
		scanf("%d",&p->data);
		p->next = NULL;
		t->next = p;
		t = p;
	}
}

void Linklist_Create_inverse(Linklist &L,int n)
{
  int i;
  printf("请输入链表的元素个数：");
  scanf("%d",&n);
  Linklist p;
  L = (Linklist)malloc(sizeof(Lnode));
  L->next = NULL;
  for(i = n;i > 0;i--)
  {
    p = (Linklist)malloc(sizeof(Lnode));
    scanf("%d",&p->data);
    p->next = L->next;
    L->next = p;
  }
}

void show()
{
  printf("**********链表菜单**********\n");
  printf("0.重新自定义表\t1.初始化表\n2.插入元素\t");
  printf("3.按元素删除\n4.按位置删除\t");
  printf("5.按元素查找\n6.按位置查找\t");
  printf("7.按元素替换\n8.按位置替换\t");
  printf("9.查看所有元素\n10.查看表长\t");
  printf("11.排序表\n12.清空表\t13.结束程序\n");
  printf("******************************\n");
}
