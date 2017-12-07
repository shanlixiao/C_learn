#include <stdio.h>
int removeElement(int *nums, int numsSize, int val) {
    int *j;
    int *i;
    for(i = nums;i <= numsSize + nums - 1;++i)
    {
      // if(numsSize > 1)
        // {
            if(*i == val)
            {
              for(j = i + 1;j <= numsSize + nums - 1;++j)
              {
                  *(j - 1) = *j;
              }
              i--;
              numsSize--;
            }//if
            if(numsSize == 0)
              *nums = 0;
    }//for
    return numsSize;
}

int main()
{
  int numsSize;
  int nums[100];
  int val,i;
  printf("numsSize:");
  scanf("%d",&numsSize);
  printf("nums:");
  for(i = 0;i < numsSize;++i)
  {
    scanf("%d",&nums[i]);
  }
  printf("val:");
  scanf("%d",&val);
  printf("numsSize: %d\n",removeElement(nums, numsSize, val));
  printf("nums:%d\n",*nums);
}
