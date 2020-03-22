#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define M 12




int main()
{
int a[N];
int b[M];
int i,j,s=0;
srand(time(NULL));
a[0] = rand()%10;
for(i=1;i<N;i++)
{
    a[i] = a[i-1]+rand()%10;
    printf("%d ",a[i]);
}
printf("\n");
b[0] = rand()%10;
for(i=1;i<M;i++)
{
    b[i] =b[i-1]+rand()%10;
    printf("%d ",b[i]);
}
for(i=0;i<M;i++)
{
    if(i!=0)
    {
        if(b[i]==b[i-1])
            continue;
    }

    j=0;
    while(a[j]!=b[i] && j<N)
    {
        j+=1;
    }
    if(j!=N)
        s+=1;
}



printf("\n%d",s);

return 0;
}






