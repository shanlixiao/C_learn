#include "head.h"

int inverse(link &L)
{
	link p,q;
	p = q = L;
	link t;
	p = p->next;
	t = p;
	while(q->next != NULL)
	{
		q = p->next->next;
		p->next->next = t;
		L->next = p->next;
		t = p->next;
		p->next = q;
	}
	q->next = t;
	L-> next = p->next;
	p->next = NULL;
	return 0;
}
int main()
{
	link L;
	int n;
	scanf("%d",&n);
	create(L,n);
	inverse(L);
	show(L,n);
}
