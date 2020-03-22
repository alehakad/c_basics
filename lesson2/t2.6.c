#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5




int main()
{
int a[N];
int i;
srand(time(NULL));
for(i=0;i<N;i++)
{
    a[i] = rand()%100;
    printf("%d ",a[i]);
}
i=0;
while(((a[i]+a[i+1])%2) && i<N-1)
{
    i+=1;
}
printf("\n");
if(i==N-1)
    printf("Yes");
else
    printf("No");



return 0;
}






