#include <stdio.h>
int connect(char string1[],char string2[],char string3[])
{
  int i = 0,j = 0;
  while(string1[i] != '\0') {
    string3[i] = string1[i];
    ++i;
  }
  while(string2[j] != '\0')
  {
    string3[i] = string2[j];
    ++i;
    ++j;
  }
  return 0;
}
int main()
{
  int n;
  scanf("%d\n",&n);
  char string[100][100];
  char string1[100][100];
  int i;
  for(i = 0;i < n;++i)
  {
    gets(string[i]);
  }
  // for(i = 0;i < n;++i)
  // {
  //   puts(string[i]);
  // }
  int j = 0;
  for(i = 0;i < n;i += 2)
  {
    connect(string[i],string[i+1],string1[j]);
    ++j;
  }
  for(i = 0;i < n/2;++i)
  {
    puts(string1[i]);
  }
}
