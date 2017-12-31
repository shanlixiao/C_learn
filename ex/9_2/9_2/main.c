#define N 5
#include <stdio.h>
void fun(char *string){
    int i,j;
    char t;
    for(i = 0,j = N - 1;i < j;++i,--j)
    {
        t = *(string + i);
        *(string + i) = *(string + j);
        *(string + j) = t;
    }
}

int main(int argc, const char * argv[]) {
    char string[N];
    printf("Please input the string:");
    gets(string);
    fun(string);
    puts(string);
    return 0;
}
