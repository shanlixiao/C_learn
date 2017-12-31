#include <stdio.h>
enum weekday { sun,mon,tue,wed,thu,fri,sat} workdday;
int main()
{
    int i,j;
    printf("input today:");
    scanf("%d",&i);
    printf("input days:");
    scanf("%d",&j);
    int n;
    n = (i + j % 7) % 7;
    enum weekday a;
    a = (enum weekday)n;
    switch(a)
    {
        case sun:printf("sunday");break;
        case mon:printf("monday");break;
        case tue:printf("tuesday");break;
        case wed:printf("wednesday");break;
        case thu:printf("thursday");break;
        case fri:printf("friday");break;
        case sat:printf("saturday");break;
    }
    printf("\n");
    return 0;
}
