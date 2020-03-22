#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define N 10




int main()
{
int a[N];
int i,max,min,maxi=0,mini=0,s=0;
srand(time(NULL));
for(i=0;i<N;i++)
{
    a[i] = rand()%100;
    printf("%d ",a[i]);
}
max = a[0];
min = a[0];

for(i=1;i<N;i++)
{
    if(a[i]>max)
    {
        max = a[i];
        maxi = i;
    }
    else
    {
    if(a[i]<min)
    {
        min =a[i];
        mini = i;

    }
    }
}
if(mini>maxi)
{
  for(i = maxi+1;i<mini;i++)
   {
       s+=a[i];
   }
}
else
{
   for(i = mini+1;i<maxi;i++)
   {
       s+=a[i];
   }
}


printf("\n%d",s);

return 0;
}













