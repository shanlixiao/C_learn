#include <stdio.h>
#include <stdlib.h>
struct ListNode{
  int val;
  struct ListNode *next;
};
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct  ListNode *p,*q;
    p = l1;
    while(p->next)
        p = p->next;
    q = l2;
    p->next = q->next;
    return l1;
}

void List_Create_order(struct ListNode *L,int n)
{
	int i;
	printf("输入链表长:\n");
	scanf("%d",&n);
	struct ListNode *p,*t;
	L = (struct ListNode*)malloc(sizeof(struct ListNode));
	L->next = NULL;
	t = L;
	printf("输入链表内容·:\n");
	for(i = n;i >0;i--)
	{
		p = (struct ListNode*)malloc(sizeof(struct ListNode));
		scanf("%d",&p->val);
		p->next = NULL;
		t->next = p;
		t = p;
	}
}

int main()
{
  struct ListNode *l1,*l2;
  int n = 3;
  int m = 3;
  List_Create_order(l1,n);
  List_Create_order(l2,m);
  mergeTwoLists(l1,l2);
}
