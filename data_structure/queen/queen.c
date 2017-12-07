#include "math.h"
#include <stdio.h>
int check(int a[],int n){
  int i,j;
  for(i = 2;i <= n;i++)
    for(j = 1;j <= i - 1;j++)
    {
      if(a[i] == a[j] || abs(a[i] - a[j]) == i - j)
        return 0;
    }
  return 1;
}

void queen(){
  int a[9];
  int i;
  int j = 0;
  for(a[1] = 1;a[1] <= 8;a[1]++)
    for(a[2] = 1;a[2] <= 8;a[2]++)
      for(a[3] = 1;a[3] <= 8;a[3]++)
        for(a[4] = 1;a[4] <= 8;a[4]++)
          for(a[5] = 1;a[5] <= 8;a[5]++)
            for(a[6] = 1;a[6] <= 8;a[6]++)
              for(a[7] = 1;a[7] <= 8;a[7]++)
                for(a[8] = 1;a[8] <= 8;a[8]++)
                  {
                    if(!check(a,8)) continue;
                    else
                    {
                      for(i = 1;i <= 8;i++)
                        printf("%d\t",a[i]);

                      j++;
                    }
                    printf("\n");
                  }
                  printf("共%d个方案",j);
}

int main(){
  queen();
}
