#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define N 10




int main()
{
int a[N];
int i,min,mind = INT_MAX;
double d;
srand(time(NULL));
for(i=0;i<N;i++)
{
    a[i] = rand()%100;
    printf("%d ",a[i]);
}

scanf("%lf",&d);

for(i=0;i<N;i++)
{
    if(abs(a[i]-d)<mind)
    {
        min = a[i];
        mind = abs(a[i]-d);
    }

}



printf("%d ",min);




return 0;
}






