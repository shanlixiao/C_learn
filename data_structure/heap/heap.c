#include <stdio.h>
#include <cstdlib>
// 数组长度
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
#define swap(a,b) (a^=b,b^=a,a^=b)

/*
 * (最大)堆的向下调整算法
 *
 * 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
 *     其中，N为数组下标索引值，如数组中第1个数对应的N为0。
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     start -- 被下调节点的起始位置(一般为0，表示从第1个开始)
 *     end   -- 截至范围(一般为数组中最后一个元素的索引)
 */
void maxheap_down(int a[], int start, int end)
{
    int c = start;			// 当前(current)节点的位置
    int l = 2*c + 1;		// 左(left)孩子的位置
    int tmp = a[c];			// 当前(current)节点的大小
    for (; l <= end; c=l,l=2*l+1)
    {
		// "l"是左孩子，"l+1"是右孩子
        if ( l < end && a[l] < a[l+1])
            l++;		// 左右两孩子中选择较大者，即m_heap[l+1]
        if (tmp >= a[l])
            break;		// 调整结束
		else			// 交换值
        {
            a[c] = a[l];
            a[l]= tmp;
        }
    }
}

/*
 * 堆排序(从小到大)
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void heap_sort_asc(int a[], int n)
{
    int i;
    // 从(n/2-1) --> 0逐次遍历。遍历之后，得到的数组实际上是一个(最大)二叉堆。
    // 从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
    for (i = n - 1; i > 0; i--)
    {
        // 交换a[0]和a[i]。交换后，a[i]是a[0...i]中最大的。
		    swap(a[0], a[i]);
		// 调整a[0...i-1]，使得a[0...i-1]仍然是一个最大堆。
		// 即，保证a[i-1]是a[0...i-1]中的最大值。
        int j;
        printf("调整后：");
        for (j = 0; j< n; j++)
          printf("%d ", a[j]);
        printf("\n");
        // printf("%d ",n);
        maxheap_down(a, 0, i-1);

    }

}

int main()
{
	int i;
  int a[10];
	int ilen = LENGTH(a);
  for(i = 0;i < ilen;i++)
    a[i] = rand() % 100;
	printf("原始队列：\n");
	for (i=0; i<ilen; i++)
		printf("%d ", a[i]);
	printf("\n");

	heap_sort_asc(a, ilen);			// 升序排列
	//heap_sort_desc(a, ilen);		// 降序排列
  printf("\n");
	printf("优先队列：");
	for (i=0; i<ilen; i++)
		printf("%d ", a[i]);
	printf("\n");
  printf("下个队列的优先级：");
  printf("%d ",a[ilen-1]);
  printf("\n");
  return 1;
}
