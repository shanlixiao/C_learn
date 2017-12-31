
#include <stdio.h>

int main(int argc, const char * argv[]) {
    char p1[100],*p2;
    scanf("%s",p1);
    int m;
    scanf("%d",&m);
    p2 = (p1 + m - 1);
    printf("%s",p2);
    return 0;
}
