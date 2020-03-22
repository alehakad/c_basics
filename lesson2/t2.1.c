#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10




int main()
{
int a[N];
int i,min,max,mini=0,maxi=0;
srand(time(NULL));
for(i=0;i<N;i++)
{
    a[i] = rand()%100;
    printf("%d ",a[i]);
}

min = a[0];
max = a[0];

for(i=0;i<N;i++)
{
    if(a[i]>max)
    {
        max =a[i];
        maxi =i ;
    }
    if(a[i]<min)
    {
        min = a[i];
        mini = i;
    }

}
a[mini] =max;
a[maxi] = min;
printf("\n");

for(i=0;i<N;i++)
{
    printf("%d ",a[i]);
}



return 0;
}






