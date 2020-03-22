#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10




int main()
{
float a[N],b[N];
int i,j,k=1;
float tmp;
srand(time(NULL));

for(i=0;i<N;i++)
{
    a[i] = (float)rand()/(float)(RAND_MAX/10);
    printf("%f ",a[i]);
}
for(i=0;i<N;i++)
{
    for(j=i+1;j<N;j++)
    {
        if(a[i]>a[j])
        {
            tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
        }
    }
}
b[0]=a[0];
for(i=1;i<N;i++)
{
    if(a[i]!=a[i-1])
    {
        b[i]=a[i];
        k+=1;
    }
}
printf("\n\n");
for(i=0;i<k;i++)
{
    printf("%f ",b[i]);
}
return 0;
}






