#include <stdio.h>
#include <limits.h>



int main()
{
int i,k,n,min = INT_MAX;
scanf("%d",&k);
for(i =1; i <= k;i++)
{
    scanf("%d",&n);
    if(n>0 && n<min)
        min = n;
}

printf("%d",min);





return 0;
}
