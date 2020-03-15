#include <stdio.h>
#include <stdlib.h>

int pd(int a)
{
    if(a%10 == a/10000 && a/10%10 == a/1000%10)
        return 1;
    else
        return 0;


}



int main()
{   int a;
    scanf("%d",&a);
    printf("%d",pd(a));
    return 0;
}
