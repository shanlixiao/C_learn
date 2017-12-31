#include <stdio.h>
#include <cstdlib>
typedef struct Linknode{
    int data;
    struct Linknode *next;
    struct Linknode *prior;
}Linknode,*Linklist;

void Linklist_Create_Order(Linklist &L,int n)
{
    int i;
    Linklist p,t;
    L = (Linklist)malloc(sizeof(Linknode));
    L->next = L;
    t = L;
    
    p = (Linklist)malloc(sizeof(Linknode));
    scanf("%d",&p->data);
    L->data = p->data;
    L->next = L;
    
    for(i = n - 1;i > 0;i--)
    {
        p = (Linklist)malloc(sizeof(Linknode));
        scanf("%d",&p->data);
        p->next = L;
        t->next = p;
        t = p;
    }
}
int main(){
    int n;
    Linklist L;
    printf("input the n:");
    scanf("%d",&n);
    int j;
    Linklist_Create_Order(L,7);
    Linklist p;
    p = (Linklist)malloc(sizeof(Linknode));
    p = L;
    printf("today is :");
    int i;
    scanf("%d",&i);
    
    while(i-1){
        p = p->next;
        i--;
    }
    while(n){
        p = p->next;
        n--;
    }
    printf("%d\n",p->data);
    return 0;
    
}
