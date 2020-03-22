#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define s 10



int main()
{
int a[N];
int ch[s] ={0};
int i,j,k,max=0;
srand(time(NULL));
for(i=0;i<N;i++)
{
    a[i] = rand()%s;
    printf("%d ",a[i]);
}
for(i=0;i<N;i++)
{
    ch[a[i]] +=1;
    }
for(i=0;i<s;i++)
{
   if(ch[i]>max)
        max= ch[i];
    }


printf("\n%d",max);

return 0;
}













