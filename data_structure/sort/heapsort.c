#include <stdio.h>
#include "head.h"

void minheap_down(SqList &L, int start, int end)
{
    int c = start;			// 当前(current)节点的位置
    int l = 2*c + 1;		// 左(left)孩子的位置
    int tmp = L.r[c].key;			// 当前(current)节点的大小
    for (; l <= end; c=l,l=2*l+1)
    {
		// "l"是左孩子，"l+1"是右孩子
        if ( l < end && L.r[l].key > L.r[l+1].key)
            l++;		// 左右两孩子中选择较小者
        if (tmp <= L.r[l].key)
            break;		// 调整结束
		else			// 交换值
        {
            L.r[c].key = L.r[l].key;
            L.r[l].key = tmp;
        }
    }
}


void heap_sort_desc(SqList &L, int n)
{
    int i;

    for (i = n / 2 - 1; i >= 1; i--)
        minheap_down(L, i, n-1);

    for (i = n - 1; i > 1; i--)
    {
        // 交换L.r[0]和L.r[i]。交换后，L.r[i]是L.r[0...i]中最小的。
		swap(L.r[1].key, L.r[i].key);
		// 调整L.r[0...i-1]，使得L.r[0...i-1]仍然是一个最小堆。
		// 即，保证L.r[i-1]是L.r[0...i-1]中的最小值。
        minheap_down(L, 1, i-1);
    }
}

// void HeapAdjust(SqList &L, int i, int length)
// {
//     int Child;
//     int temp;
//     for(;2 * i + 1 < length; i = Child)
//     {
//         //子节点的位置 = 2 * (parent(父结点)) + 1
//         Child = 2 * i + 1;
//         //得到子结点中较大的结点
//         if(Child < length - 1 && L.r[Child + 1].key > L.r[Child].key)
//                 ++Child;
//         //如果较大的子结点大于父结点那么把较大的子结点往上移动
//         //替换它的父结点
//         if(L.r[i].key < L.r[Child].key)
//         {
//             swap(L.r[i].key,L.r[Child].key);
//         }
//         else
//                 break;
//     }
// }
// //堆排序算法
// void HeapSort(SqList &L, int length)
// {
//     int i;
//     for(i = length/2 - 1; i >= 1; --i)
//             HeapAdjust(L, i, length);
//     for(i = length - 1; i > 1; --i)
//     {
//         swap(L.r[0].key,L.r[i].key);                  //递归调整
//     }
// }

int main()
{
    SqList L;
    Input(L);
    time(&t1);
    heap_sort_desc(L,MAXSIZE);
    time(&t2);
    Output(L);
    char string[] = "快速排序的时间:";
    // Output_file(t1,t2,string);
    printf("%lds\n",t2-t1);
    return 0;
}
