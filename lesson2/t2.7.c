#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3




int main()
{
int a[N];
int i,l = N/2 + N%2;
srand(time(NULL));
for(i=0;i<N;i++)
{
    a[i] = rand()%2;
    printf("%d ",a[i]);
}
i=0;
while(a[i] == a[N-i-1] && i<l)
{
    i+=1;
}
printf("\n");
if(i==l)
    printf("Yes");
else
    printf("No");




return 0;
}






