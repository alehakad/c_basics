#include <stdio.h>




int main()
{
int i,n;
float k,a,max;
scanf("%d",&n);
scanf("%f",&k);
for(i =1; i <= n;i++)
{
    scanf("%f",&a);
    if(a>k)
        max = a;
}

printf("%f",max);





return 0;
}
