#include <stdio.h>
int compare(char *s1,char *s2){
  char *p = s1;
  char *q = s2;
  while(*p != '\0' && *p != '\0'){
    if(*p == *q){
      ++p;
      ++q;
    }
    else return(*p - *q);
  }
  if(*p != '\0') return (int(*p));
  else if(*q != '\0') return (int(*q));
  else return 0;
}

int main(){
  char *s1,*s2;
  scanf("%s%s",s1,s2);
  printf("%d",compare(s1,s2));
  return 0;
}
